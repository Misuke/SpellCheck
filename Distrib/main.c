/*
 * main.c	-- programme principal
 *
 * Copyright © 2013 Erick Gallesio - Polytech'Nice-Sophia <eg@unice.fr>
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date:  5-Jan-2013 20:17 (eg)
 * Last file update:  8-Jan-2013 23:20 (eg)
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "corpus.h"
#include "correct.h"

int main(int argc, char* argv[])
{
  if (argc != 2) {
    fprintf(stderr, "Usage: %s mot-a-corriger\n", *argv);
    exit(EXIT_FAILURE);
  }

  /* Créer la table de hash */
  hash_table_create();

  /* Initialiser le corpus */
  if (! init_corpus_from_file("Data/Iliad.txt"))
    return EXIT_FAILURE;

  /* proposer une correction éventuelle */
  printf("%s ==> %s\n", argv[1], correct_word(argv[1]));

  /* Terminer */
  hash_table_destroy();
  return EXIT_SUCCESS;
}
