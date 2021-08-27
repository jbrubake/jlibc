/**************************************************************************
 * @file assert.h
 * @author Jeremy Brubaker
 * @brief Runtime assertions
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

/* This header is *not* idempotent, therefore, no include-guards */

#include <stdlib.h>

#undef assert

#ifdef NDEBUG
    #define assert(exp) ((void)0)
#else
    void __assert (char *);
    #define __STR(x) __VAL(x)
    #define __VAL(x) #x
    #define assert(exp) ((exp) ? ((void)0) : __assert (__FILE__ ":" __STR(__LINE__) ": Assertion '" #exp "' failed."))
#endif

