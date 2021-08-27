#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"


CuSuite *string_suite ();
CuSuite *stdio_suite ();

/****************************
 * Run the tests
 ***************************/
int
main (int argc, char **argv)
{
    CuString *output = CuStringNew();

    CuSuite* strsuite = CuSuiteNew();
    CuSuiteAddSuite (strsuite, string_suite ());
    CuSuiteRun(strsuite);
    CuSuiteSummary(strsuite, output);
    CuSuiteDetails(strsuite, output);
    printf("%s\n", output->buffer);


    CuSuite* stdiosuite = CuSuiteNew();
    CuSuiteAddSuite (stdiosuite, stdio_suite ());
    CuSuiteRun(stdiosuite);
    CuSuiteSummary(stdiosuite, output);
    CuSuiteDetails(stdiosuite, output);
    printf("%s\n", output->buffer);

    CuStringDelete(output);
    CuSuiteDelete(strsuite);

    return strsuite->failCount + stdiosuite->failCount;
}

