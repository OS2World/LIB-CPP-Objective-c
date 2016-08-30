/* Interface for GNU Objective-C Object category that keeps a retain count.
   Copyright (C) 1993,1994 Free Software Foundation, Inc.
   
   Written by:  R. Andrew McCallum <mccallum@gnu.ai.mit.edu>
   Date: July 1994
   
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

#ifndef __ObjectRetaining_h_OBJECTS_INCLUDE
#define __ObjectRetaining_h_OBJECTS_INCLUDE

#include <objects/stdobjects.h>
#include <objects/Retaining.h>

void objc_retain_object (id anObj);
void objc_release_object (id anObj);
unsigned objc_retain_count (id anObj);

extern id autorelease_class;

@interface Object (ObjectRetaining) <Retaining>
@end

#endif /* __ObjectRetaining_h_OBJECTS_INCLUDE */
