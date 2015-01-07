/*
 * correct.c	-- Correction d'un mot
 *
 * Copyright © 2013-2014 Erick Gallesio - Polytech'Nice-Sophia <eg@unice.fr>
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date:  6-Jan-2013 07:28 (eg)
 * Last file update: 18-Dec-2014 00:16 (eg)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "correct.h"
#include "hash.h"


static char **allocate_corrections(size_t size)
{
  int nbCorrectionsAvailable = 54 * size + 25;
  char **correctionsAvailable = (char **)malloc(nbCorrectionsAvailable * sizeof(char *));
  for (int i = 0; i < nbCorrectionsAvailable; ++i)
    correctionsAvailable[i] = (char *)malloc(size * sizeof(char *));

  return correctionsAvailable;
}

static int deletions(char *word, char **corrections, int index)
{
  char *tmp = malloc(sizeof(word) - sizeof(char));
  int position = 0;

  for (int i = 0; word[i]; ++i, ++index)
  {
    for (int j = 0; word[j]; ++j)
    {
      if (i == j) continue;

      tmp[position++] = word[j];
    }

    position = 0;
    corrections[index] = strdup(tmp);
  }

  free(tmp);
  return index;
}

static int transpositions(char *word, char **corrections, int index)
{
  char *tmp = malloc(sizeof(word));
  strcpy(tmp, word);

  for (int i = 0; tmp[i+1]; ++i, ++index)
  {
    tmp[i] = word[i+1];
    tmp[i+1] = word[i];
    corrections[index] = strdup(tmp);
  }

  free(tmp);
  return index;
}

static int alterations(char *word, char **corrections, int index)
{
  char *tmp = malloc(sizeof(word));
  strcpy(tmp, word);

  for (int i = 0; tmp[i]; ++i)
  {
    for (int j = 0; ALPHABET[j]; ++j, ++index)
    {
      if (tmp[i] == ALPHABET[j]) continue;

      tmp[i] = ALPHABET[j];
      corrections[index] = strdup(tmp);
    }
    tmp[i] = word[i];
  }

  free(tmp);
  return index;
}

static int inserts(char *word, char **corrections, int index)
{
  char *tmp = malloc(sizeof(word) + sizeof(char));
  int length = strlen(word) + 1;
  int position = 0;

  for (int i = 0; i < length; ++i)
  {
    for (int j = 0; ALPHABET[j]; ++j, ++index)
    {
      tmp[i] = j;
      for (int k = 0; word[k]; ++k, ++position)
      {
        if (k == i) ++position;
        tmp[position] = word[k];
      }

      position = 0;
      corrections[index] = strdup(tmp);
    }
  }

  free(tmp);
  return index;
}

static char *better_candidate(char *word, char **corrections, int index)
{
  char *better = malloc(sizeof(word) + sizeof(char));
  int nbOccur = 0;
  int bestOccur = 0;

  for (int i = 0; i < index; ++i)
  {
    nbOccur = hash_table_search(corrections[i]);
    if (nbOccur > bestOccur)
    {
      strcpy(better, corrections[i]);
      bestOccur = nbOccur;
    }
  }

  return (bestOccur == 0) ? NULL : better;
}

static char *try_2_errors(char **corrections, int index)
{
  return NULL;
}

static void destroy_corrections(char **corrections, int index)
{
  for (int i = 0; i < index; ++i)
    free(corrections[i]);
  free(corrections);
}

static char **build_corrections(char *word, int *size)
{
  char **corrections = allocate_corrections(strlen(word));
  int index = 0;

  if (corrections == NULL) {
    fprintf(stderr, "cannot allocate the array of corrections");
    exit(EXIT_FAILURE);
  }

  /* construires une liste de mots possibles */
  index = deletions(word, corrections, index);
  index = transpositions(word, corrections, index);
  index = alterations(word, corrections, index);
  index = inserts(word, corrections, index);

  *size = index;
  return corrections;
}

static char *find_correction(char *word)
{
  char *result;
  int index = 0;
  char **corrections = build_corrections(word, &index);

  /* choisir le meilleur candidat entre word et les corrections possibles du mot */
  result = better_candidate(word, corrections, index);

  if (! result) {
    /* Pas de correction avec  une seule erreur pour "word" */
    if (DEBUG) printf("Pas de correction avec une distance de 1 pour '%s'\n", word);

    /* Pour commencer, écrivez une version de try_2_errors qui renvoie
     * toujours NULL. Ainsi, vous ne proposerez pas de solution à deux
     * erreurs */
    result = try_2_errors(corrections, index);
  }

  /* un peu de ménage avant de renvoyer le meilleur candidat */
  result = strdup(result? result: word);
  destroy_corrections(corrections, index);
  return result;
}

/* propose une correction plausible pour le mot word. Si aucune
   correction n'est trouvée, on renvoie le mot lui même */
char *correct_word(char *word)
{
  if (hash_table_is_present(word))
    return word;

  char *correctWord = find_correction(word);
  return correctWord ? correctWord : word;
}
