/**************************************************************************
 * @file strerror.c
 * @author Jeremy Brubaker
 * @brief strerror(3)
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
#include <errno.h>
#include <string.h>

/* TODO: this should be defined in errno.h */
/* #define _MAX_ERROR 200 */

char *
(_strerror) (int errnum, char *dest)
{
    static char sbuf[] = "Error #xxx";
    char *buf = sbuf;

    if (dest)
        buf = dest;

    switch (errnum)
    {
        case 0:
            return "No error";
            break;
        case EDOM:
            return "Numerical argument out of domain";
            break;
        case EILSEQ:
            return "Invalid or incomplete multibyte or wide character";
            break;
        case ERANGE:
            return "Numerical result out of range";
            break;
        default:
            if (errnum < 0 || errnum >= sys_nerr)
                return "Unknown error";

            buf[9]  = errnum % 10 + '0';
            buf[8]  = (errnum / 10) % 10 + '0';
            buf[7]  = (errnum / 100) + '0';
            return buf;
            break;
    }
}

char *
(strerror) (int errnum)
{
    return _strerror (errnum, NULL);
}

