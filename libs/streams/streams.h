#ifndef JOB_STREAMS_H
#define JOB_STREAMS_H

#include <stdio.h>

#include "../data_structures/matrix/matrix.h"

void fill_matrix(int *matrix, size_t sizeOfMatrix, int *query, size_t queryCount);

int countNeighbors(int *matrix, int n, int m, int col, int row);
void liveGame(int *matrix, size_t n, size_t m);

#endif //JOB_STREAMS_H