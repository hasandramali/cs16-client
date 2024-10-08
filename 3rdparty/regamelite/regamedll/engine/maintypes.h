/*
*
*    This program is free software; you can redistribute it and/or modify it
*    under the terms of the GNU General Public License as published by the
*    Free Software Foundation; either version 2 of the License, or (at
*    your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but
*    WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*    In addition, as a special exception, the author gives permission to
*    link the code of this program with the Half-Life Game Engine ("HL
*    Engine") and Modified Game Libraries ("MODs") developed by Valve,
*    L.L.C ("Valve").  You must obey the GNU General Public License in all
*    respects for all of the code used other than the HL Engine and MODs
*    from Valve.  If you modify this file, you may extend this exception
*    to your version of the file, but you are not obligated to do so.  If
*    you do not wish to do so, delete this exception statement from your
*    version.
*
*/

#ifndef MAINTYPES_H
#define MAINTYPES_H
#ifdef _WIN32
#pragma once
#endif

#include "osconfig.h"
#include "mathlib.h"

// Has no references on multiplayer library CS.
#define NOXREF
// Function body is not implemented.
#define NOBODY
// Function is not tested at all.
#define UNTESTED
// Function is doubt reversed
#define TODOBODY

#define BIT(n) (1<<(n))

#ifdef HAVE_STRONG_TYPEDEF
enum class string_t: unsigned int {};
#else
typedef unsigned int string_t;
#endif

typedef int EOFFSET;
typedef int BOOL;
typedef unsigned char byte;
typedef unsigned short word;
#define _DEF_BYTE_

#ifndef __cplusplus
	#undef true
	#undef false
	typedef enum {false, true} qboolean;
#else
	typedef int qboolean;
#endif // #ifndef __cplusplus

// From engine/server.h
typedef enum sv_delta_s
{
	sv_packet_nodelta,
	sv_packet_delta,
} sv_delta_t;

#endif // MAINTYPES_H
