/*
 * main.c	-- programme principal
 *
 * Copyright © 2013 Erick Gallesio - Polytech'Nice-Sophia <eg@unice.fr>
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date:  5-Jan-2013 20:17 (eg)
 * Last file update:  5-Jan-2013 22:21 (eg)
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(void)
{
  hash_table_create();
  /* Remplissage de la table */
  hash_table_add("foo");
  hash_table_add("bar");
  hash_table_add("BAR"); /* converti en minuscules avant ajout dans table */

  /* Recherche dans la table */
  printf("foo présent? %d\n", hash_table_is_present("foo"));
  printf("bar présent? %d\n", hash_table_is_present("bar"));
  printf("zoo présent? %d\n", hash_table_is_present("zoo"));

  /* Afficher la valeur associée à un mot */
  printf("Nombre d'occurences de foo: %d\n", hash_table_search("foo"));
  printf("Nombre d'occurences de bar: %d\n", hash_table_search("bar"));
  printf("Nombre d'occurences de zoo: %d\n", hash_table_search("zoo"));

  hash_table_destroy();
  return EXIT_SUCCESS;
}
