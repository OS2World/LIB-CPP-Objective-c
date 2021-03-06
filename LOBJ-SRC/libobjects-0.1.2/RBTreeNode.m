/* Implementation for Objective-C RBTreeNode objects
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

#include <objects/RBTreeNode.h>

@implementation RBTreeNode

+ initialize
{
  if (self == [RBTreeNode class])
    [self setVersion:0];	/* beta release */
  return self;
}

- init
{
  [super init];
  _red = YES;
  return self;
}

- (void) encodeWithCoder: (Coder*)aCoder
{
  [super encodeWithCoder:aCoder];
  [aCoder encodeValueOfType:@encode(BOOL) at:&_red withName:"RBTreeNode isRed"];
}

+ newWithCoder: (Coder*)aCoder
{
  RBTreeNode *n = [super newWithCoder:aCoder];
  [aCoder decodeValueOfType:@encode(BOOL) at:&(n->_red) withName:NULL];
  return n;
}

- write: (TypedStream*)aStream
{
  [super write:aStream];
  objc_write_type(aStream, @encode(BOOL), &_red);
  return self;
}

- read: (TypedStream*)aStream
{
  [super read:aStream];
  objc_read_type(aStream, @encode(BOOL), &_red);
  return self;
}

- (BOOL) isRed
{
  return _red;
}

- setRed
{
  _red = YES;
  return self;
}

- setBlack
{
  _red = NO;
  return self;
}

@end
