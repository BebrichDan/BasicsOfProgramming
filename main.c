#include <stdio.h>
#include "libs/file_io/file_test.h"
#include "libs/streams/streams.h"
#include "libs/streams/testStreams.h"

int main(void)
{
    testAll_fill_matrix();

    testAll_liveGame();

    testAll_MedianFilter();

    testAll_arrayDomainsWithPairedCounter();

    testAll_getMinLexicographicallyStr();

    testAll_getMaxBinThree();

    testAll_getShuffledString();

    printf("holla\n");
    return 0;
}
