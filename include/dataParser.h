#ifndef DATAPARSER_H
#define DATAPARSER_H
/*!
 *  \file dataParser.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:02:39
 *
 *  \brief Header file for dataParser.c
 *
 *
 */

// Including library headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "analyser.h"
#include "dataAPI.h"
/*!
 \def EXIT_SUCCESS
 \brief Exit code confirming program proper execution
*/
#define EXIT_SUCCESS 0
/*!
 \def ERREUR_SAISIE
 \brief Exit code stating that an error occured
*/
#define ERREUR_SAISIE -1

/*!
 *  \fn void explode(char *srcStr)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sam 17 Juin 2023 - 14:42:05
 *  \brief explode a string into a datastruct element
 *  \param srcStr : string to explode
 *  \param data : pointer to the dataStruct to be filled
 *  \remarks
 */
void explode(char *srcStr, dataStruct *data);

/*!
 *  \fn void parseFile(int method, FILE *fileHandler)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:52:14
 *  \brief Function to parse a file
 *  \param method : method to use
 *  \param fileHandler : pointer to the fileHandler
 *  \remarks
 */
void parseFile(int method, FILE *fileHandler);

#endif