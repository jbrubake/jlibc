/**************************************************************************
 * @file memcpy.c
 * @author Jeremy Brubaker
 * @brief memcpy(3)
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

void *
(memcpy) (void *s1, const void *s2, size_t n)
{
    /* No requirement to check for NULL
     * pointers or overlapping regions */

    char *c1 = s1;
    const char *c2 = s2;

    for (; n > 0; n--)
        *c1++ = *c2++;

    return s1;
}

