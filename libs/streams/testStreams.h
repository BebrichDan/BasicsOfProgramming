#ifndef JOB_TEST_STREAMS_H
#define JOB_TEST_STREAMS_H

#include <stdio.h>
#include <stdlib.h>

#include "../string/tasks/string.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__);
//1
void testAll_fill_matrix();
//2
void testAll_liveGame();
//3
void testAll_MedianFilter();
//4
void testAll_arrayDomainsWithPairedCounter();
//5
void testAll_getQuantitySubmatrices();
//6
void testAll_getMinLexicographicallyStr();
//7
void testAll_getMaxBinThree();
//8
void testAll_getShuffledString();
//9
void testAll_fileWithSmallerValues();
//10
void testAll_outputFileInChunks();

#endif //JOB_TEST_STREAMS_H