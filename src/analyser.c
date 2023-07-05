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

double stdDev(double data[], int length)
{
    double sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < length; ++i)
    {
        sum += data[i];
    }
    mean = sum / (double)length;
    for (i = 0; i < length; ++i)
    {
        SD += pow(data[i] - mean, 2);
    }
    return sqrt(SD / (double)length);
}

double computeMean(double data[], int length)
{
    double sum = 0.0, mean;
    int i;
    for (i = 1; i < length; i++)
    {
        sum += (data[i] - data[i - 1]);
    }
    mean = sum / (double)length;
    return mean;
}

void computeMaxAndMin(double data[], int length, double *max, double *min)
{
    *max = data[1] - data[0];
    *min = data[1] - data[0];
    double tmp = 0.0;
    for (int i = 1; i < length; i++)
    {
        tmp = data[i] - data[i - 1];
        if (tmp > *max)
        {
            *max = tmp;
        }
        if (tmp < *min)
        {
            *min = tmp;
        }
    }
}

void analyseFileByTimestamp(dataStruct *dat, int dataLength)
{
    double stdDeviation = 0.0;
    double meanTime = 0.0;
    double maxTime = 0.0;
    double minTime = 0.0;
    double tmp = 0.0;
    double *timeStamps = malloc(sizeof(double) * dataLength);
    for (int i = 0; i < dataLength; i++)
    {
        timeStamps[i] = dat[i].timestamp_sec;
    }
    stdDeviation = stdDev(timeStamps, dataLength);
    meanTime = computeMean(timeStamps, dataLength);
    computeMaxAndMin(timeStamps, dataLength, &maxTime, &minTime);
    FILE *output = fopen("outputTimeStamp.txt", "w+");
    /* Ecriture de la data */
    for (int i = 1; i < dataLength; i++)
    {
        tmp = timeStamps[i] - timeStamps[i - 1];
        if (tmp < 0.02)
        {
            fprintf(output, "%d\t%f\n", i - 1, tmp);
        }
    }
    fclose(output);
    printf("Parsing file by timestamp\n");
    printf("Average time between two frames: %f\n", meanTime);
    printf("Max time between two frames: %f\n", maxTime);
    printf("Min time between two frames: %f\n", minTime);
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
