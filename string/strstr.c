/**************************************************************************
 * @file strstr.c
 * @author Jeremy Brubaker
 * @brief strstr(3)
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
(strstr) (const char *haystack, const char *needle)
{
    /* Automatically match a null search string
     * to the beginning of the string */
    if (*needle == '\0')
        return (char *)haystack;

    /* Loop through each occurrence of the
     * initial character in 'needle' */
    const char *s; 
    while ((s = strchr (haystack, *needle)))
    {
        /* Save possible answer and needle */
        char *r = (char *)s;
        char *n = (char *)needle;

        /* Check each character in needle
         * against string */
        for (n++, s++; ; n++, s++)
        {
            if (!*n) /* If *n is NULL we have an answer */
                return r;
            if (*n != *s) /* If different, try again */
                break;
        }

        haystack++; /* start searching at next character */
    }

    return NULL; /*not found so return NULL */
}

