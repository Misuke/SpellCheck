#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

/* creation de la table */
void hash_table_create(void)
{
    hcreate(HASH_TABLE_SIZE);
}

/* destruction de la table */
void hash_table_destroy(void)
{
    hdestroy();
}

/* renvoie 1 si word est dans la table, 0 sinon */
int hash_table_is_present(char *word)
{
    if(hash_table_search(word) != 0)
        return 1;

    return 0;
}

/* renvoie le nombre d'occurences de word dans la table (0 si absent) */
int hash_table_search(char *word)
{
    ENTRY e, *ep;

    e.key = word;

    ep = hsearch(e, FIND);
    return ep ? (int)(ep->data) : 0;
}

/* ajoute word dans la table */
void hash_table_add(char *word)
{
    //word = strlower(word);
    ENTRY e, *ep;

    e.key = word;
    e.data = (void *) 1;
    ep = hsearch(e, FIND);

    if (ep)
        ep->data = ep->data + 1;
    else
        ep = hsearch(e, ENTER);

    if (ep == NULL) {
        fprintf(stderr, "entry failed\n");
        exit(EXIT_FAILURE);
    }
}

char* strlower(char *word) {
    char *str = strdup(word);
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}
