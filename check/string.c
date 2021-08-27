#include <stdlib.h>
#include "CuTest.h"

/****************************
 * Checked Headers
 ***************************/
#include <string.h>

/****************************
 * Tests
 ***************************/
void
test_strcmp_equal (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "Hello world";
    int actual = strcmp (s1, s2);
    int expected = 0;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strcmp_s1_less (CuTest *tc)
{
    char s1[] = "Hello planet";
    char s2[] = "Hello world";
    int actual = strcmp (s1, s2);
    int expected = -1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strcmp_s2_less (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "Hello planet";
    int actual = strcmp (s1, s2);
    int expected = 1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strcmp_s1_null (CuTest *tc)
{
    char s1[] = "";
    char s2[] = "Hello planet";
    int actual = strcmp (s1, s2);
    int expected = -1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strcmp_s2_null (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "";
    int actual = strcmp (s1, s2);
    int expected = 1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strncmp_equal (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "Hello world";
    int  n    = 11;
    int actual = strncmp (s1, s2, n);
    int expected = 0;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strncmp_s1_less (CuTest *tc)
{
    char s1[] = "Hello planet";
    char s2[] = "Hello world";
    int  n    = 11;
    int actual = strncmp (s1, s2, n);
    int expected = -1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strncmp_s2_less (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "Hello planet";
    int  n    = 11;
    int actual = strncmp (s1, s2, n);
    int expected = 1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strncmp_s1_less_n_small (CuTest *tc)
{
    char s1[] = "Hello planet";
    char s2[] = "Hello world";
    int  n    = 9;
    int actual = strncmp (s1, s2, n);
    int expected = -1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strncmp_s1_less_n_big (CuTest *tc)
{
    char s1[] = "Hello planet";
    char s2[] = "Hello world";
    int  n    = 20;
    int actual = strncmp (s1, s2, n);
    int expected = -1;
    CuAssertIntEquals (tc, expected, actual);
}
void
test_strncmp_s1_less_n_equal (CuTest *tc)
{
    char s1[] = "Hello planet";
    char s2[] = "Hello world";
    int  n    = 6;
    int actual = strncmp (s1, s2, n);
    int expected = 0;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strncmp_s2_less_n_small (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "Hello planet";
    int  n    = 9;
    int actual = strncmp (s1, s2, n);
    int expected = 1;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_strncmp_s2_less_n_big (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "Hello planet";
    int  n    = 20;
    int actual = strncmp (s1, s2, n);
    int expected = 1;
    CuAssertIntEquals (tc, expected, actual);
}
void
test_strncmp_s2_less_n_equal (CuTest *tc)
{
    char s1[] = "Hello world";
    char s2[] = "Hello equal";
    int  n    = 6;
    int actual = strncmp (s1, s2, n);
    int expected = 0;
    CuAssertIntEquals (tc, expected, actual);
}

void
test_memcpy (CuTest *tc)
{
    /* TODO: need to test malloc first */
    char *s1 = (char *)malloc (11 * sizeof (char));
    char *s2 = "Hello world";
    size_t n = 11;
    char *expected = s2;
    char *actual = memcpy ((void *)s1, (void *)s2, n);
    CuAssertStrEquals (tc, expected, actual);
}

/****************************
 * Test Suites
 ***************************/
CuSuite *
string_suite ()
{
    CuSuite* suite = CuSuiteNew ();

    SUITE_ADD_TEST (suite, test_strcmp_equal);
    SUITE_ADD_TEST (suite, test_strcmp_equal);
    SUITE_ADD_TEST (suite, test_strcmp_s1_less);
    SUITE_ADD_TEST (suite, test_strcmp_s2_less);
    SUITE_ADD_TEST (suite, test_strcmp_s1_null);
    SUITE_ADD_TEST (suite, test_strcmp_s2_null);
    SUITE_ADD_TEST (suite, test_strncmp_equal);
    SUITE_ADD_TEST (suite, test_strncmp_s1_less);
    SUITE_ADD_TEST (suite, test_strncmp_s2_less);
    SUITE_ADD_TEST (suite, test_strncmp_s1_less_n_small);
    SUITE_ADD_TEST (suite, test_strncmp_s1_less_n_big);
    SUITE_ADD_TEST (suite, test_strncmp_s1_less_n_equal);
    SUITE_ADD_TEST (suite, test_strncmp_s2_less_n_small);
    SUITE_ADD_TEST (suite, test_strncmp_s2_less_n_big);
    SUITE_ADD_TEST (suite, test_strncmp_s2_less_n_equal);
    SUITE_ADD_TEST (suite, test_memcpy);

    return suite;
}

