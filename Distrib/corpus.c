#include <stdio.h>
#include "corpus.h"

int init_corpus_from_file(char *filename)
{
    char *buffer, *token;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "file error");
        exit(EXIT_FAILURE);
    }

    if (fgets(str, buffer, 255, file))
    {
        for (token = strtok(str, SEPARATORS); token; token = strtok(NULL, SEPARATORS))
            hash_table_add(token);
    }

    fclose(file);
}
