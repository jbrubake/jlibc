/**************************************************************************
 * @file memcmp.c
 * @author Jeremy Brubaker
 * @brief memcmp(3)
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
(memcmp) (const void *s1, const void *s2, size_t n)
{
    const unsigned char *sp1 = s1;
    const unsigned char *sp2 = s2;

    for (; n > 0; n--, sp1++, sp2++)
        if (*sp1 != *sp2)
            return (*sp1 < *sp2 ? -1 : 1);

    return 0;
}

