/**************************************************************************
 * @file getline.c
 * @author Jeremy Brubaker
 * @brief getline(3)
 *
 * \bug {
 * - getline() is not thread-safe
 * }
 *
 * This file is part of XXX
 *
 * Copyright (c) 2020, Jeremy Brubaker
 ***************************************************************************
 * XXX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * XXX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with XXX.  If not, see <https://www.gnu.org/licenses/>.
 **************************************************************************/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t
(getline) (char **lineptr, size_t *n, FILE* stream)
{
    size_t BUFSZ;
    size_t CURRSZ;
    size_t nn = 0;

    /* Return -1 if an invalid pointer is passed */
    if (lineptr == NULL || n == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    CURRSZ = BUFSZ = *n ? *n : 200;


    /* If lineptr has not been allocated, do so now */
    if (*lineptr == NULL && *n == 0)
    {
        if (!(*lineptr = (char *) malloc (BUFSZ * sizeof (char))))
            return -1;
    }

    int c;
    char *line = *lineptr;
    while ((c = getc (stream)))
    {
        *line++ = c; /* add character to string */
        nn++; /* increment current byte count */

        /* If not enough space, allocate BUFSZ more bytes */
        if (nn == BUFSZ - 1)
        {
            *n += nn; /* add to total byte count */
            nn = 0; /* reset current byte count */
            CURRSZ += BUFSZ; /* increase size by BUFSZ */
            if (!(*lineptr = realloc (*lineptr, CURRSZ)))
                return -1;

            /* Find the current end of the string */
            for (line = *lineptr; *line; line++)
                ;
        }

        /* Break out on end of line or end of file */
        if (c == '\n' || c == EOF)
            break;
    }

    /* Terminate string and complete byte count */
    *line = '\0';
    *n += nn;

    /* Return -1 on EOF */
    return c == EOF ? -1 : *n;
}
