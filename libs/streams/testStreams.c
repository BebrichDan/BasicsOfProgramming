#include <stdio.h>
#include <time.h>
#include "streams.h"
#include "testStreams.h"

//1
void testAll_fill_matrix()
{
    int n = 3;
    int count_query = 2;
    int matrix[n][n];

    int query[2][4] = {{1, 1, 2, 2},
                       {0, 0, 1, 1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    fill_matrix(*matrix, n, *query, count_query);
    int resMatrix[3][3] = {{1, 1, 0},
                           {1, 2, 1},
                           {0, 1, 1}};

    for (int z = 0; z < n; z++)
    {
        for (int x = 0; x < n; x++)
        {
            assert(matrix[z][x] == resMatrix[z][x]);
        }
    }
}

//2
void testAll_liveGame()
{
    int n = 4;
    int m = 3;
    int matrix[4][3] = {{0, 1, 0},
                        {0, 0, 1},
                        {1, 1, 1},
                        {0, 0, 0}};

    liveGame(*matrix, n, m);

    int resMatrix[4][3] = {{0, 0, 0},
                           {1, 0, 1},
                           {0, 1, 1},
                           {0, 1, 0}};
    for (int z = 0; z < n; z++)
    {
        for (int x = 0; x < m; x++)
        {
            assert(matrix[z][x] == resMatrix[z][x]);
        }
    }
}

//3
void testAll_MedianFilter()
{
    int filter = 5;
    int n = 7;
    int m = 7;

    int matrix[3][3] = {{10, 20, 30},
                        {25, 35, 45},
                        {15, 25, 35}};
    int res_matrix[3][3] = {{10, 20, 30},
                            {25, 25, 45},
                            {15, 25, 35}};

    int matrix2[7][7] = {{8, 9,  1, 3, 2,  4, 6},
                         {1, 11, 1, 3, 8,  9, 2},
                         {2, 5,  3, 6, 7,  4, 2},
                         {8, 6,  4, 9, 7,  1, 3},
                         {4, 3,  7, 2, 1,  8, 4},
                         {5, 6,  5, 7, 8,  8, 4},
                         {1, 2,  1, 9, 10, 5, 9}};
    int res_matrix2[7][7] = {{8, 9,  1, 3, 2,  4, 6},
                             {1, 11, 1, 3, 8,  9, 2},
                             {2, 5,  4, 4, 4,  4, 2},
                             {8, 6,  5, 6, 4,  1, 3},
                             {4, 3,  5, 6, 5,  8, 4},
                             {5, 6,  5, 7, 8,  8, 4},
                             {1, 2,  1, 9, 10, 5, 9}};

    medianFilter(*matrix, 3, 3, 3);
    for (int z = 0; z < 3; z++)
    {
        for (int x = 0; x < 3; x++)
        {
            assert(matrix[z][x] == res_matrix[z][x]);
        }
    }

    medianFilter(*matrix2, filter, n, m);
    for (int z = 0; z < n; z++)
    {
        for (int x = 0; x < m; x++)
        {
            assert(matrix2[z][x] == res_matrix2[z][x]);
        }
    }
}

//4
void testAll_arrayDomainsWithPairedCounter()
{
    char stats[] = "cpdomains = [\"900 google.mail.com\", \"50 yahoo.com\", \"1 intel.mail.com\", \"5 wiki.org\"]\0";
    vectorVoid res = arrayDomainsWithPairedCounter(stats);

    DomainCounter expDomains[] = {{951, "com"},
                                  {900, "google.mail.com"},
                                  {1,   "intel.mail.com"},
                                  {901, "mail.com"},
                                  {5,   "org"},
                                  {5,   "wiki.org"},
                                  {50,  "yahoo.com"}};

    assert(sizeof(expDomains) / sizeof(DomainCounter) == res.size);
    for (int i = 0; i < res.size; i++)
    {
        DomainCounter domain;
        getVectorValueV(&res, i, &domain);
        assert(expDomains[i].counter == domain.counter);
        ASSERT_STRING(expDomains[i].domain, domain.domain);
    }
}

//5
void testAll_getQuantitySubmatrices()
{
    int n = 3;
    int m = 3;

    int test[3][3] = {{1, 0, 1},
                      {1, 1, 0},
                      {1, 1, 0}};
    matrix newMatrix = createMatrixFromArray(*test, n, m);

    int res = getQuantitySubmatrices(&newMatrix);
    assert(res == 13);
}

//6
void testAll_getMinLexicographicallyStr()
{
    char *pattern1 = "IIIDIDDD";
    char *pattern2 = "DDD";

    char *res1 = getMinLexicographicallyStr(pattern1);
    char *res2 = getMinLexicographicallyStr(pattern2);

    ASSERT_STRING("123549876", res1)
    ASSERT_STRING("4321", res2)
}

//7
void testAll_getMaxBinThree()
{
    int nums[6] = {3, 2, 1, 6, 0, 5};

    vectorVoid res = getMaxBinThree(nums, sizeof(nums) / sizeof(int));

    int test[9] = {6, 3, 5, -1, 2, 0, -1, -1, 1};
    assert(sizeof(test) / sizeof(int) == res.size);

    for (int i = 0; i < res.size; i++)
    {
        TreeItem treeItem;
        getVectorValueV(&res, i, &treeItem);
        assert(test[i] == treeItem.value);
    }
}

//8
void testAll_getShuffledString() {
    char s[] = "abap";
    int indices[] = {0,3,2,1};

    char *res = getShuffledString(s, indices, 4);

    ASSERT_STRING("apab\0", res)
}

//9
void testAll_fileWithSmallerValues() {
    int n = 700;
    srand((unsigned) time(NULL));
    FILE *fp = fopen ("file_test1.txt", "w+");

    int expArray[1000];
    int idx = 0;
    for (int i = 0; i < 1000; i++) {
        int val = rand();
        if (val < n) {
            expArray[idx++] = val;
        }
        fprintf(fp, "%d\n", val);
    }
    fclose(fp);

    size_t res = fileWithValuesLessN("file_test1.txt", "file_test2.txt", n);
    assert(idx == res);
}

//10
void testAll_outputFileInChunks() {
    int n = 15;
    srand((unsigned) time(NULL));
    FILE *fp = fopen ("file_test3.txt", "w+");

    for (int i = 0; i < 1000; i++) {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);

    outputFileByNLines("file_test3.txt", n);
}