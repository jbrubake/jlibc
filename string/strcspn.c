/**************************************************************************
 * @file strcspn.c
 * @author Jeremy Brubaker
 * @brief strcspn(3)
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

size_t
(strcspn) (const char *s, const char *reject)
{
    size_t n = 0;
    for (n = 0; *s; s++, n++)
        for (const char *r = reject; *r; r++)
            if (*s == *r) return n;

    return n;
}

