/**************************************************************************
 * @file strcmp.c
 * @author Jeremy Brubaker
 * @brief strncmp(3)
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

int
(strncmp) (const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (*(unsigned char *)s1 > *(unsigned char *)s2)
            return 1;
        else if (*(unsigned char *)s1 < *(unsigned char *)s2)
            return -1;

        /* Break on end of string */
        ++s1; ++s2;
        if (!*s1) break;
        if (!*s2) break;
    }

    if (*s1 && *s2) /* strings are the same */
        return 0;
    else if (*s1) /* s1 is shorter */
        return 1;
    else /* s2 is shorter */
        return -1;
}
