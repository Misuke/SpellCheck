/*
 * corpus.c	-- Creation du corpus pour travailler
 *
 * Copyright © 2013 Erick Gallesio - Polytech'Nice-Sophia <eg@unice.fr>
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date:  5-Jan-2013 21:59 (eg)
 * Last file update:  8-Jan-2013 23:12 (eg)
 */

#ifndef _CORPUS_H
#define _CORPUS_H
#define SEPARATORS  "  \t\n\r.,:;`/\"+-_(){}[]<>*&^%$#@!?~/|\\=1234567890"

int init_corpus_from_file(char *filename);
#endif
