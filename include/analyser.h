#ifndef ANALYSER_H
#define ANALYSER_H
/*! 
 *  \file analyser.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sam 17 Juin 2023 - 16:31:17
 *
 *  \brief Header file for analyser.c - contains functions to statistically analyse a CAN Attack File
 *
 *
 */

// Including library headers
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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
 *  \fn float stdDev(float data[], int length)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 19 Juin 2023 - 19:21:07
 *  \brief Calculate the standard deviation of a float array
 *  \param data: the data to analyse
 *  \param length: the length of the data array
 *  \return the standard deviation of the data array
 *  \remarks
 */
float stdDev(float data[], int length);

/*!
 *  \fn void analyseFileByTimestamp(dataStruct *dat, int dataLength)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:57:10
 *  \brief Analyse file using timestamp and differences over it
 *  \param dat: the data to analyse
 * \param dataLength: the length of the data array
 *  \remarks
 */
void analyseFileByTimestamp(dataStruct *dat, int dataLength);

/*!
 *  \fn void analyseFileByData(dataStruct *dat, int dataLength)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:57:10
 *  \brief Analyse file using data and differences over it
 *  \param dat: the data to analyse
 *  \param dataLength: the length of the data array
 *  \remarks
 */
void analyseFileByData(dataStruct *dat, int dataLength);

/*!
 *  \fn void analyseFileByIdentifier(dataStruct *dat, int dataLength)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:57:10
 *  \brief Analyse file using identifier and differences over it
 *  \param dat: the data to analyse
 *  \param dataLength: the length of the data array
 *  \remarks
 */
void analyseFileByIdentifier(dataStruct *dat, int dataLength);

/*!
 *  \fn void handleAnalyseFieldAndMethod(int selected_method, dataStruct *dat)
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 19 Juin 2023 - 18:37:29
 *  \brief Handles the analysis of a file according to a method
 *  \param selected_method: the method to use for the analysis
 *  \param dat: the data to analyse
 *  \param dataLength: the length of the data array
 *  \remarks
 */
void handleAnalyseFieldAndMethod(int selected_method, dataStruct *dat, int dataLength);

#endif