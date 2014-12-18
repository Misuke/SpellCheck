/*
 * main.c	-- programme principal
 *
 * Copyright © 2013 Erick Gallesio - Polytech'Nice-Sophia <eg@unice.fr>
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date:  5-Jan-2013 20:17 (eg)
 * Last file update:  8-Jan-2013 22:51 (eg)
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "corpus.h"

int main(void)
{
  hash_table_create();
  if (! init_corpus_from_file("Data/strtok.txt"))
    return EXIT_FAILURE;

  /* On teste quelque mots */
  printf("occurences de strtok: %d (9)\n",     hash_table_search("strtok"));
  printf("occurences de the: %d (22)\n",       hash_table_search("the"));
  printf("occurences de abracadabra: %d (0)\n",hash_table_search("abracadabra"));

  hash_table_destroy();
  return EXIT_SUCCESS;
}
