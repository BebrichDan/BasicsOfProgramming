#include <stdio.h>
#include "libs/file_io/file_test.h"
#include "libs/streams/streams.h"
#include "libs/streams/testStreams.h"

int main(void)
{
    testAll_fill_matrix();

    testAll_liveGame();

    testAll_MedianFilter();

    printf("holla");
    return 0;
}
