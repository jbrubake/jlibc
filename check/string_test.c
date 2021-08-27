#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (void) {
    char *buf1 = (char *)malloc (100 * sizeof (char));
    char *buf2 = (char *)malloc (100 * sizeof (char));
    char *s1;
    char *s2;

    printf ("%s\n", "memcpy");
    s1 = buf1;
    s2 = buf2;
    strcpy (s2, "Hello world");
    size_t n = strlen (s2);
    memcpy ((void *)s1, (void *)s2, n);
    printf ("s1: %s\ns2: %s\n", s1, s2);

    printf ("\n%s\n", "memchr");
    printf ("%s\n", (char *)memchr (s1, 'w', 10));
    if (memchr (s1, 'w', 1) == NULL)
        printf ("%s\n", "NULL");

    printf ("\n%s\n", "memmove");
    s2 = buf2;
    s1 = s2 + 5;
    strcpy (s2, "hello world");
    memmove (s1, s2, n);
    printf ("s2: %s\ns1: %s\n", s2, s1);

    printf ("\n%s\n", "memset");
    s1 = buf1;
    memset (s1, 'x', 5);
    printf ("s1: %s\n", s1);

    printf ("\n%s\n", "memcmp");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "test");
    strcpy (s2, "test");
    printf ("%d\n", memcmp (s1, s2, 4));
    strcpy (s1, "testing");
    strcpy (s2, "testsss");
    printf ("%d\n", memcmp (s1, s2, 7));
    printf ("%d\n", memcmp (s1, s2, 4));
    strcpy (s2, "asdfing");
    printf ("%d\n", memcmp (s1, s2, 10));

    printf ("\n%s\n", "strncat");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "string");
    strcpy (s2, " test");
    strncat (s1, s2, 5);
    printf ("%s\n", s1);
    strcpy (s1, "string");
    strcpy (s2, " test");
    strncat (s1, s2, 10);
    printf ("%s\n", s1);
    strcpy (s1, "string");
    strcpy (s2, " test");
    strncat (s1, s2, 3);
    printf ("%s\n", s1);

    printf ("\n%s\n", "strlen");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "Hello planet");
    printf ("%ld\n", strlen (s1));

    printf ("\n%s\n", "strlen");
    s1 = buf1;
    s2 = buf2;
    strncpy (s1, "Hello world", 7);
    s1[7] = '\0';
    printf ("%s\n", s1);

    printf ("\n%s\n", "strcspn");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "Hello world");
    printf ("%ld\n", strcspn (s1, "xz"));

    printf ("\n%s\n", "strspn");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "Hello world");
    printf ("%ld\n", strspn (s1, "lHe"));

    printf ("\n%s\n", "strpbrk");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "Hello world");
    printf ("%s\n", strpbrk (s1, "wx"));

    printf ("\n%s\n", "strrchr");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "Hello world");
    printf ("%s\n", strrchr (s1, 'l'));

    printf ("\n%s\n", "strchr");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "Hello world");
    printf ("%s\n", strchr (s1, 'w'));

    printf ("\n%s\n", "strstr");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "Hello world how are you");
    printf ("%s\n", strstr (s1, "world"));
    if (strstr (s1, "planet") == NULL)
        printf ("%s\n", "NULL");

    printf ("\n%s\n", "strerror");
    printf ("%s\n", strerror (EDOM));
    printf ("%s\n", strerror (0));
    printf ("%s\n", strerror (123));
    printf ("%s\n", strerror (2123));
    printf ("%s\n", strerror (-123));

    printf ("\n%s\n", "perror");
    errno = EDOM;
    perror ("ERROR");
    perror ("");

    printf ("\n%s\n", "strtok");
    s1 = buf1;
    s2 = buf2;
    strcpy (s1, "asdf;; qwer,jkl,,; ");
    printf ("%s\n", strtok (s1, ",; "));
    printf ("%s\n", strtok (NULL, ",; "));
    printf ("%s\n", strtok (NULL, ",; "));
    printf ("%s\n", strtok (NULL, ",; "));
}
