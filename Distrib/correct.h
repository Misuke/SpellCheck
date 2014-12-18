/*
 * correct.c	-- Correction d'un mot
 *
 * Copyright © 2013 Erick Gallesio - Polytech'Nice-Sophia <eg@unice.fr>
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date:  6-Jan-2013 07:28 (eg)
 * Last file update:  8-Jan-2013 23:11 (eg)
 */

/* Si un mot M n'apparait pas dans notre corpus, on va essayer de le
 * corriger en construisant un ensemble des mots plausibles à partir
 * de M. Pour cela, on va construire des mots où il y a:
 *     - un effacement : un caractère supprimé de M
 *     - un caractère transposé: échange de deux lettre adjacentes de M
 *     - un replacement: un caractère de M est remplacé par une autre lettre
 *     - une insertion: un caractère de l'alphabet est inséré dans M
 *
 * Ainsi, si le mot est '1234', on aura: 
 * - deletions ->
 *     ['234', '134', '124', '123']
 *  - transpositions ->
 *     ['2134', '1324', '1243']
 *  - replaces ->
 *     ['a234', 'b234', 'c234', 'd234', 'e234', 'f234', 'g234',
 *      'h234', 'i234', 'j234', 'k234', 'l234', 'm234', 'n234',
 *      'o234', 'p234', 'q234', 'r234', 's234', 't234', 'u234',
 *      'v234', 'w234', 'x234', 'y234', 'z234', '1a34', '1b34',
 *      '1c34', '1d34', '1e34', '1f34', '1g34', '1h34', '1i34',
 *      '1j34', '1k34', '1l34', '1m34', '1n34', '1o34', '1p34',
 *      '1q34', '1r34', '1s34', '1t34', '1u34', '1v34', '1w34',
 *      '1x34', '1y34', '1z34', '12a4', '12b4', '12c4', '12d4',
 *      '12e4', '12f4', '12g4', '12h4', '12i4', '12j4', '12k4',
 *      '12l4', '12m4', '12n4', '12o4', '12p4', '12q4', '12r4',
 *      '12s4', '12t4', '12u4', '12v4', '12w4', '12x4', '12y4',
 *      '12z4', '123a', '123b', '123c', '123d', '123e', '123f',
 *      '123g', '123h', '123i', '123j', '123k', '123l', '123m',
 *      '123n', '123o', '123p', '123q', '123r', '123s', '123t',
 *      '123u', '123v', '123w', '123x', '123y', '123z']
  *   - insertions ->
 *     ['a1234', 'b1234', 'c1234', 'd1234', 'e1234', 'f1234', 'g1234',
 *      'h1234', 'i1234', 'j1234', 'k1234', 'l1234', 'm1234', 'n1234',
 *      'o1234', 'p1234', 'q1234', 'r1234', 's1234', 't1234', 'u1234',
 *      'v1234', 'w1234', 'x1234', 'y1234', 'z1234', '1a234', '1b234',
 *      '1c234', '1d234', '1e234', '1f234', '1g234', '1h234', '1i234',
 *      '1j234', '1k234', '1l234', '1m234', '1n234', '1o234', '1p234',
 *      '1q234', '1r234', '1s234', '1t234', '1u234', '1v234', '1w234',
 *      '1x234', '1y234', '1z234', '12a34', '12b34', '12c34', '12d34',
 *      '12e34', '12f34', '12g34', '12h34', '12i34', '12j34', '12k34',
 *      '12l34', '12m34', '12n34', '12o34', '12p34', '12q34', '12r34',
 *      '12s34', '12t34', '12u34', '12v34', '12w34', '12x34', '12y34',
 *      '12z34', '123a4', '123b4', '123c4', '123d4', '123e4', '123f4',
 *      '123g4', '123h4', '123i4', '123j4', '123k4', '123l4', '123m4',
 *      '123n4', '123o4', '123p4', '123q4', '123r4', '123s4', '123t4',
 *      '123u4', '123v4', '123w4', '123x4', '123y4', '123z4', '1234a',
 *      '1234b', '1234c', '1234d', '1234e', '1234f', '1234g', '1234h',
 *      '1234i', '1234j', '1234k', '1234l', '1234m', '1234n', '1234o',
 *      '1234p', '1234q', '1234r', '1234s', '1234t', '1234u', '1234v',
 *      '1234w', '1234x', '1234y', '1234z']
*/

#ifndef _CORRECT_H
#define _CORRECT_H
#define ALPHABET    "abcdefghijklmnopqrstuvwxyz"

/* propose une correction plausible pour le mot word. Si aucune
   correction n'est trouvée, on renvoie le mot lui même */
char *correct_word(char *word);
#endif
