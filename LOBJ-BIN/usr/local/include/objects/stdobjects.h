/* General purpose definitions for the GNU Objective-C Library.
   Copyright (C) 1993,1994 Free Software Foundation, Inc.

   Written by:  R. Andrew McCallum <mccallum@gnu.ai.mit.edu>
   Date: May 1993

   This file is part of the GNU Objective C Class Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/ 

#ifndef __stdobjects_h_OBJECTS_INCLUDE
#define __stdobjects_h_OBJECTS_INCLUDE

#include <objects/config.h>
#include <stdlib.h>
#include <stdarg.h>
#include <objects/objc-gnu2next.h>

#if NeXT_runtime
 #include <objc/objc.h>
 #include <objc/objc-class.h>
 #include <objc/objc-runtime.h>
 #ifndef _C_ATOM
  #define _C_ATOM '%'
 #endif
 #define _F_CONST    0x01
 #define _F_IN       0x01
 #define _F_OUT      0x02
 #define _F_INOUT    0x03
 #define _F_BYCOPY   0x04
 #define _F_ONEWAY   0x08
 #define _C_CONST    'r'
 #define _C_IN       'n'
 #define _C_INOUT    'N'
 #define _C_OUT      'o'
 #define _C_BYCOPY   'O'
 #define _C_ONEWAY   'V'
 #define CLASS Class
#else				/* GNU Objective C Runtime */
 #include <objc/objc.h>
 #include <objc/objc-api.h>
 #include <objc/encoding.h>
 #include <objc/sarray.h>

/* Patches to work with OS/2 (case insensitive file system!) (6.2.95 tb) */
/* #include <objc/list.h> */
 #include "/emx/include/objc/list.h"
/* end of patches (6.2.95 tb) */

 #define CLASS Class*
#endif

#include <objc/Object.h>
#include <objects/objc-malloc.h>

/* The following two lines are maintained by the libobjects Makefile */
#define OBJECTS_VERSION 0.1.2
#define OBJECTS_GCC_VERSION 2.6.1

extern const char objects_version[];
extern const char objects_gcc_version[];
#if NeXT_cc
extern const char objects_NeXT_cc_version[];
#endif

#define LAMBDA(RETTYPE, ARGS, BODY) \
({RETTYPE __lambda_func ARGS BODY __lambda_func;})

#define LAMBDA_VOID_PERFORM(SELECTOR) \
LAMBDA(void, (id _o), {[_o perform: SELECTOR];})

#define LAMBDA_ID_PERFORM(SELECTOR) \
LAMBDA(id, (id _o), {return [_o perform: SELECTOR];})

#define LAMBDA_BOOL_PERFORM(SELECTOR) \
LAMBDA(BOOL, (id _o), {if ([_o perform:SELECTOR]) return YES; else return NO;})


#ifndef MAX
#define MAX(a,b) \
       ({typedef _ta = (a), _tb = (b);  \
         _ta _a = (a); _tb _b = (b);     \
         _a > _b ? _a : _b; })
#endif

#ifndef MIN
#define MIN(a,b) \
       ({typedef _ta = (a), _tb = (b);  \
         _ta _a = (a); _tb _b = (b);     \
         _a < _b ? _a : _b; })
#endif

#ifndef PTR2LONG
#define PTR2LONG(P) (((char*)(P))-(char*)0)
#endif
#ifndef LONG2PTR
#define LONG2PTR(L) (((char*)0)+(L))
#endif

#endif /* __stdobjects_h_OBJECTS_INCLUDE */



