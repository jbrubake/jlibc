#include "CuTest.h"

/****************************
 * Checked Headers
 ***************************/
#include <stdio.h>

/****************************
 * Tests
 ***************************/
void
test_getline_null_values (CuTest *tc)
{
    ssize_t actual = getline (NULL, NULL, stdin);
    ssize_t expected = -1;
    CuAssertIntEquals (tc, expected, actual);
}

/****************************
 * Test Suites
 ***************************/
CuSuite *
stdio_suite ()
{
    CuSuite* suite = CuSuiteNew ();

    SUITE_ADD_TEST (suite, test_getline_null_values);

    return suite;
}

