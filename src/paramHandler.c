/*!
 *  \file paramHandler.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:03:35
 *
 *  \brief Source file for paramHandler.h - contains functions to handle program parameters
 *
 *
 */

#include "paramHandler.h"

int getMethod(int argc, char **argv, int position)
{
    int method = -1;
    if (position < argc)
    {
        if (strcmp(argv[position], TIMESTAMP_METHOD) == 0 || strcmp(argv[position], IDENTIFIER_METHOD) == 0 || strcmp(argv[position], DATA_METHOD) == 0)
        {
            method = atoi(argv[position]);
        }
    }
    return (method);
}

void copyFileHandler(int argc, char **argv, int position, FILE **fileHandler)
{
    if (position < argc)
    {
        *fileHandler = fopen(argv[position], "r");
    }
    if (*fileHandler == NULL)
    {
        printf("Error while opening file\n");
    }
}

int paramParser(int argc, char **argv, FILE **fileHandler)
{
    int method = -1;
    if (argc >= 3)
    {
        for (int i = 1; i < argc; i += 2)
        {
            if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "-file") == 0)
            {
                copyFileHandler(argc, argv, i + 1, fileHandler);
            }
            else if (strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "-method") == 0)
            {
                method = getMethod(argc, argv, i + 1);
            }
        }
    }
    return method;
}