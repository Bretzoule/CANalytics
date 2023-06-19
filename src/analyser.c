/*!
 *  \file analyser.c
 *  \author LEFLOCH Thomas <leflochtho@eisti.eu>
 *  \version 0.1
 *  \date Sam 17 Juin 2023 - 16:30:43
 *
 *  \brief Source file for analyser.h - contains functions to statistically analyse a CAN Attack File
 *
 *
 */

#include "analyser.h"


float stdDev(float data[], int length)
{
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < length; ++i)
    {
        sum += data[i];
    }
    mean = sum / length;
    for (i = 0; i < length; ++i)
    {
        SD += pow(data[i] - mean, 2);
    }
    return sqrt(SD / length);
}

void analyseFileByTimestamp(dataStruct *dat, int dataLength)
{
    float stdDeviation = 0.0;
    float *timeStamps = malloc(sizeof(float) * dataLength);
    for (int i = 0; i < dataLength; i++)
    {
        timeStamps[i] = dat[i].timestamp_sec;
    }
    stdDeviation = stdDev(timeStamps, dataLength);
    printf("Parsing file by timestamp\n");
    printf("Standard deviation: %f\n", stdDeviation);
    free(timeStamps);
}

void analyseFileByIdentifier(dataStruct *dat, int dataLength)
{

    printf("Parsing file by identifier\n");
}

void analyseFileByData(dataStruct *dat, int dataLength)
{
    float averageDataSize = 0.0;
    for (int i = 0; i < dataLength; i++)
    {
        averageDataSize += dat[i].dlc;
    }
    averageDataSize /= dataLength;
    printf("Analysing file by data\n");
    printf("Average data size: %f\n", averageDataSize);
}

void handleAnalyseFieldAndMethod(int selected_method, dataStruct *dat, int dataLength)
{
    switch (selected_method)
    {
    case timestamp:
        analyseFileByTimestamp(dat, dataLength);
        break;
    case identifier:
        analyseFileByIdentifier(dat, dataLength);
        break;
    case data:
        analyseFileByData(dat, dataLength);
        break;
    default:
        printf("Error: unknown method\n");
        break;
    }
}
