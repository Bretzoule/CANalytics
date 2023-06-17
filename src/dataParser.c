/*!
 *  \file dataParser.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:02:43
 *
 *  \brief Source file for dataParser.h - contains functions to parse a CAN Attack File
 *
 *
 */

#include "dataParser.h"

#define LINE_MAX 1024


char line[LINE_MAX];

/*!
 *  \fn void explode(char *srcStr)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sam 17 Juin 2023 - 14:42:05
 *  \brief explode a string into a datastruct element
 *  \param
 *  \return
 *  \remarks
 */
void explode(char *srcStr, dataStruct *data)
{
    char *tok;
    char *src = malloc(strlen(srcStr) + 1);
    memcpy(src, srcStr, strlen(srcStr) + 1);

    tok = strtok(src, ";");
    if (tok == NULL)
    {
        printf("no tokens found");
        free(src);
    }
    data->timestamp_sec = atof(tok);
    tok = strtok(NULL, ";");
    strncpy(data->id, tok, 4);
    data->rtr = tok[5] - '0';
    tok = strtok(NULL, ";");
    data->dlc = tok[0] - '0';
    if (data->dlc != 0)
    {
        data->data = malloc(strlen(tok));
        strcpy(data->data, tok + 1);
    }
    else
    {
        data->data = NULL;
    }
    free(src);
}

void parseFile(int method, FILE *fileHandler)
{
    dataStruct *dataArray;
    int fileLength = 0;
    while (fgets(line, LINE_MAX, fileHandler) != NULL)
    {
        fileLength++;
        dataArray = realloc(dataArray, sizeof(dataStruct) * (fileLength));
        dataStruct data;
        explode(line, &data);
        dataArray[fileLength] = data;
    }
    handleAnalyseFieldAndMethod(method, dataArray);
}