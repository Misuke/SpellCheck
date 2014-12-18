/*
 * hash.h	-- Gestion de hash-table
 *
 * Copyright © 2013 Erick Gallesio - Polytech'Nice-Sophia <eg@unice.fr>
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date:  5-Jan-2013 20:00 (eg)
 * Last file update:  8-Jan-2013 23:06 (eg)
 */

#ifndef _HASH_H
#define _HASH_H
#include <search.h>

#define HASH_TABLE_SIZE 100000

/* creation de destruction de la table */
void hash_table_create(void);
void hash_table_destroy(void);

/* renvoie 1 si word est dans la table, 0 sinon */
int hash_table_is_present(char *word);

/* renvoie le nombre d'occurences de word dans la table (0 si absent) */
int hash_table_search(char *word);

/* ajoute word dans la table */
void hash_table_add(char *word);
#endif
