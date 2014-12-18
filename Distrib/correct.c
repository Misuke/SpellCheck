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

char *correct_word(char *word)
{
  if (hash_table_is_present(word))
    return word;
  else {
    char *correct = find_correction(word);

    return correct? correct: word;
  }
}
