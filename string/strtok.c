/**************************************************************************
 * @file strtok.c
 * @author Jeremy Brubaker
 * @brief strtok(3)
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
#include <string.h>

char *
(strtok) (char *str, const char *delim)
{
    static char *s = ""; /* static to keep working on same string */
    char *d = (char *)delim;

    /* Tokenize a new string if passed */
    if (str)
        s = str;
    
    /* Skip leading delimiter characters */
    while (*d)
    {
        if (*s == *d)
        {
            s++;
            d = (char *)delim;
        }
        else
            d++;
    }

    /* Return NULL if skipping leading delimeter
     * characters reached the end of the string */
    if (!*s)
    {
        s = ""; /* reset for safety */
        return NULL;
    }

    char *r = s; /* save current location to return later */

    /* Keep getting next character until it matches a delimeter */
    while (*s)
    {
        for (d = (char *)delim; *d; d++)
        {
            if (*s == *d)
            {
                *s++ = '\0'; /* Replace delimeter with \0 to tokenize */
                return r;
            }
        }
        s++;
    }
    return r;
}

