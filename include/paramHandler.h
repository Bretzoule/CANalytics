#ifndef PARAMHANDLER_H
#define PARAMHANDLER_H
/*!
 *  \file paramHandler.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:03:48
 *
 *  \brief Header file for paramHandler.c
 *
 *
 */

// Including library headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
 *  \fn int getMethod(int argc, char **argv, int position)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:18:04
 *  \brief get method from parameters
 *  \param argc : number of parameters
 *  \param argv : array of parameters
 *  \param position : position of the method in the array
 *  \return int : method selected
 */
int getMethod(int argc, char **argv, int position);

/*!
 *  \fn void copyFileHandler(int argc, char **argv, int position, FILE** fileHandler)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:29:44
 *  \brief copies the fileHandler from the parameters
 *  \param argc : number of parameters
 *  \param argv : array of parameters
 *  \param position : position of the fileHandler in the array
 *  \param fileHandler : pointer to the fileHandler
 *  \remarks
 */
void copyFileHandler(int argc, char **argv, int position, FILE **fileHandler);

/*!
 *  \fn int paramParser(int argc, char **argv, FILE** fileHandler)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:04:53
 *  \brief Function to parse program parameters
 *  \param argc : number of parameters
 *  \param argv : array of parameters
 *  \param fileHandler : pointer to the fileHandler
 *  \return int : method selected for the parsing of the file
 */
int paramParser(int argc, char **argv, FILE **fileHandler);

#endif