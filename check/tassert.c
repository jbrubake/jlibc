#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int TEST_VAL;

void
sigabrt (int sig)
{
    if (TEST_VAL == 0)
    {
        printf ("%s", "Testing assert...FAILED\n");
        exit (1);
    }
    else if (TEST_VAL == 2)
    {
        printf ("%s", "Testing assert...FAILED (NDEBUG set)\n");
        exit (1);
    }
    else if (TEST_VAL == 1)
    {
        printf ("%s", "Testing assert...OK\n");
        exit (0);
    }
}

int
main (void)
{
    if (signal (SIGABRT, sigabrt) == SIG_ERR)
    {
        fprintf (stderr, "%s\n", "Error installing SIGABRT handler");
        exit (1);
    }

#define NDEBUG
#include <assert.h>
    TEST_VAL = 2;
    assert (TEST_VAL == 0);

#undef NDEBUG
#include <assert.h>
    TEST_VAL = 0;
    assert (TEST_VAL == 0);

    TEST_VAL = 1;
    assert (TEST_VAL == 0);
}
