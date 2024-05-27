#ifndef JOB_TEST_STREAMS_H
#define JOB_TEST_STREAMS_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__);

void testAll_fill_matrix();

void testAll_liveGame();

#endif //JOB_TEST_STREAMS_H