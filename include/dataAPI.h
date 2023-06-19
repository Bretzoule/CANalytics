#ifndef DATAAPI_H
#define DATAAPI_H

/*!
 *  \file dataAPI.h
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Lun 12 Juin 2023 - 15:53:50
 *
 *  \brief api for Method Handling
 *
 *
 */

// Including library headers
/*!
 *  \def TIMESTAMP_METHOD
 *  \brief Timestamp method analysis
 */
#define TIMESTAMP_METHOD "1"

/*!
 *  \def IDENTIFIER_METHOD
 *  \brief identifier method analysis
 */
#define IDENTIFIER_METHOD "2"

/*!
 *  \def DATA_METHOD
 *  \brief Timestamp method analysis
 */
#define DATA_METHOD "3"

/*!
 *  \enum method
 *  \brief Enum for method
 */

enum method
{
    timestamp = 1,  /*!< timestamp method */
    identifier = 2, /*!< identifier method */
    data = 3        /*!< data method */
};

/*!
 *  \struct dataStructure
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sam 17 Juin 2023 - 14:53:16
 *  \brief Contains elements of structure
 *  \param
 *  \remarks
 */
typedef struct dataStruct
{
    long timestamp_sec;
    char id[4];
    int rtr;
    int dlc;
    char *data;
} dataStruct;

#endif