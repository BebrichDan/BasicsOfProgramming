#include <stdio.h>
#include "streams.h"


void fill_matrix(int *matrix, size_t sizeOfMatrix, int *query, size_t queryCount)
{
    int (*tempMatrix)[sizeOfMatrix] = (int (*)[sizeOfMatrix]) matrix;
    int (*tempQuery)[4] = (int (*)[4]) query;

    for (int i = 0; i < queryCount; i++)
    {
        int *curQuery = tempQuery[i];

        for (int row = curQuery[0]; row <= curQuery[2]; row++)
        {
            for (int col = curQuery[1]; col <= curQuery[3]; col++)
            {
                tempMatrix[row][col]++;
            }
        }
    }
}