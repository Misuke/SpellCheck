#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corpus.h"
#include "hash.h"

int init_corpus_from_file(char *filename)
{
    char buffer[255];
    char *token;
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "file error");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, 255, file))
    {
        for (token = strtok(buffer, SEPARATORS); token; token = strtok(NULL, SEPARATORS))
            hash_table_add(token);
    }

    fclose(file);
    return 1;
}
