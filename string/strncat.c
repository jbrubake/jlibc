/**************************************************************************
 * @file strncat.c
 * @author Jeremy Brubaker
 * @brief strncat(3)
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
(strncat) (char *dest, const char *src, size_t n)
{
    char *s = dest;

    for (; *dest; dest++);

    for (; n > 0 && *src; n--)
        *dest++ = *src++;

    *dest = '\0';

    return s;
}

