/**************************************************************************
 * @file memchr.c
 * @author Jeremy Brubaker
 * @brief memchr(3)
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
(memchr) (const void *s, int c, size_t n)
{
    unsigned char *sp = (unsigned char *)s;
    unsigned char uc = c;

    for (; n > 0; sp++, n--)
    {
        if (*sp == uc)
            return (void *)sp;
    }

    return NULL;
}

