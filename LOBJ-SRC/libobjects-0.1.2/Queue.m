/* Implementation for Objective-C Queue object
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

#include <objects/Queue.h>
#include <objects/ArrayPrivate.h>

@implementation Queue
  
+ initialize
{
  if (self == [Queue class])
    [self setVersion:0];	/* beta release */
  return self;
}

- enqueueElement: (elt)newElement
{
  [self prependElement:newElement];
  return self;
}

/* Overriding */
- addElement: (elt)anElement
{
  [self enqueueElement:anElement];
  return self;
}

- (elt) dequeueElement
{
  return [self removeLastElement];
}

// OBJECT-COMPATIBLE MESSAGE NAMES;

- enqueueObject: newObject
{
  return [self enqueueElement:newObject];
}

- dequeueObject
{
  return [self dequeueElement].id_u;
}

@end