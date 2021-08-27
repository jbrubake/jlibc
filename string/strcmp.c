/**************************************************************************
 * @file strcmp.c
 * @author Jeremy Brubaker
 * @brief strcmp(3)
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

int
(strcmp) (const char *s1, const char *s2)
{
    for (; *s1 && *s2; s1++, s2++)
    {
        if (*(unsigned char *)s1 > *(unsigned char *)s2)
            return 1;
        else if (*(unsigned char *)s1 < *(unsigned char *)s2)
            return -1;
    }

    if (*s1) /* s1 is shorter */
        return 1;
    else if (*s2) /* s2 is shorter */
        return -1;
    else /* strings are the same */
        return 0;
}

