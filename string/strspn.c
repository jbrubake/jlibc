/**************************************************************************
 * @file strspn.c
 * @author Jeremy Brubaker
 * @brief strspn(3)
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
(strspn) (const char *s, const char *accept)
{
    const char *sp = s;

    for (; *sp; sp++)
        for (const char *a = accept; ; a++)
            if (*a == '\0')
                return sp - s;
            else if (*sp == *a)
                break;

    return sp - s;
}

