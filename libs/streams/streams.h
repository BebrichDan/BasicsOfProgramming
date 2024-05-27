#ifndef JOB_STREAMS_H
#define JOB_STREAMS_H

#include <stdio.h>

#include "../data_structures/matrix/matrix.h"

void fill_matrix(int *matrix, size_t sizeOfMatrix, int *query, size_t queryCount);

int countNeighbors(int *matrix, int n, int m, int col, int row);
void liveGame(int *matrix, size_t n, size_t m);

int compareInts1(const void *intPtr1, const void *intPtr2);
void medianFilter(int *matrix, int filter, int n, int m);
int calculateMedianVector(int *matrix, int max_col, int row, int col, int *arrayOfNums, int filter_size);

#endif //JOB_STREAMS_H