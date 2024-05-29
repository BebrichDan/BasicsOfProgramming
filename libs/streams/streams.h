#ifndef JOB_STREAMS_H
#define JOB_STREAMS_H

#include <stdio.h>

#include "../data_structures/matrix/matrix.h"
#include "../string/tasks/string.h"
#include "../file_io/file.h"
#include "../data_structures/vectorVoid/vectorVoid.h"

#define STATS_HEADER "cpdomains = ["
#define STATS_END "]"

//1
void fill_matrix(int *matrix, size_t sizeOfMatrix, int *query, size_t queryCount);

//2
int countNeighbors(int *matrix, int n, int m, int col, int row);
void liveGame(int *matrix, size_t n, size_t m);

//3
int compareInts1(const void *intPtr1, const void *intPtr2);
int calculateMedianVector(int *matrix, int max_col, int row, int col, int *arrayOfNums, int filter_size);
void medianFilter(int *matrix, int filter, int n, int m);

//4
#define STATS_HEADER "cpdomains = ["
#define STATS_END "]"
typedef struct DomainRecord {
    long counter;
    WordDescriptor domain;
} DomainRecord;

typedef struct DomainCounter {
    long counter;
    char domain[255];
} DomainCounter;

void parsedDomainStat(vectorVoid *data, char *start, char *end);
int compareDomainCounterNames(const void *domainCounterPtr1, const void *domainCounterPtr2);
vectorVoid arrayDomainsWithPairedCounter(char *stats);

//5
int getQuantitySubmatrices(matrix *m);

//6
char *getMinLexicographicallyStr(char *pattern);

//7
typedef struct TreeItem {
    int level;
    int value;
    int type;
    int idx;
} TreeItem;

int compareTreeItemByLevel(const void *treeItemPtr1, const void *treeItemPtr2);
void getMaxTreeImpl(int *nums, int level, int start, int end, int type, int *idx, vectorVoid *res);
vectorVoid getMaxBinThree(int *nums, int len);

//8
char* getShuffledString(char *symbols, int *indices, int len);

//9
size_t fileWithValuesLessN(char *fileInputPath, char *fileOutputPath, int n);

//10
void outputFileByNLines(char *fileInputPath, int n);

#endif //JOB_STREAMS_H