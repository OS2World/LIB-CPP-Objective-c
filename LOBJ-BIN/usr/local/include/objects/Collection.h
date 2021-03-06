/* Interface for Objective-C Collection object
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

/* This is the abstract superclass that satisfies the Collecting
   protocol, without using any instance variables.
*/

#ifndef __Collection_h_INCLUDE_GNU
#define __Collection_h_INCLUDE_GNU

#include <objects/stdobjects.h>
#include <objc/Object.h>
#include <objects/Collecting.h>
#include <objects/stdobjects.h>
#include <objects/collhash.h>
#include <objects/Coding.h>
#include <objects/Coder.h>

@interface Collection : Object <Collecting, Coding>
{
}

+ initialize;

- printElement: (elt)anElement;
- printForDebugger;

@end

// #warning fix this macro
#define FOR_COLL(ACOLL, ELT) \
{ \
   void *_es = [ACOLL initEnumState]; \
   while ([ACOLL getNextElement:&(ELT) withEnumState:&_es]) \
     {

#define FOR_COLL_END \
     } \
   [ACOLL freeEnumState:_es]; \
}

/* The only subclassResponsibilities in Collection are:

      addElement:
      removeElement:
      getNextElement:withEnumState:
      empty

   But subclasses may need to override the following for correctness:

      contentType
      comparisonFunction

   but subclasses will want to override others as well in order to 
   increase efficiency, especially:

      count

   and perhaps:

      includesElement:
      occurrencesOfElement:
      uniqueContents
      withElementsCall:whileTrue:
      withElementsCall:
      isEmpty
      freeObjects

*/

#endif /* __Collection_h_INCLUDE_GNU */

