/**************************************************************************
 * @file errno.h
 * @author Jeremy Brubaker
 * @brief errno(3)
 *
 * \bug {
 * - errno is *not* threadsafe
 * }
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
#ifndef __ARCH_ARM64_ERRNO_H
#define __ARCH_ARM64_ERRNO_H

#define __EDOM        1
#define __EILSEQ      2
#define __EINVAL      3
#define __ERANGE      4
#define __MAX_ERROR   5

#endif
