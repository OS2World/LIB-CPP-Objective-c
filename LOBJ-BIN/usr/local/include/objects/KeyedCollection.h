/* Interface for Objective-C KeyedCollection collection object
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

#ifndef __KeyedCollection_h_INCLUDE_GNU
#define __KeyedCollection_h_INCLUDE_GNU

#include <objects/stdobjects.h>
#include <objects/Collection.h>
#include <objects/KeyedCollecting.h>

@interface KeyedCollection : Collection <KeyedCollecting>

@end

/* The only subclassResponsibilities in IndexedCollection are:

      keyDescription
      insertElement:atKey:
      removeElementAtKey:
      elementAtKey:
      includesKey:
      getNextKey:content:withEnumState:
*/

#endif /* __KeyedCollection_h_INCLUDE_GNU */
