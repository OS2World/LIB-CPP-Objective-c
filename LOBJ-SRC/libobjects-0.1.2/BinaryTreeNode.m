/* Implementation for Objective-C BinaryTreeNode object
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

#include <objects/BinaryTreeNode.h>

@implementation BinaryTreeNode

+ initialize
{
  if (self == [BinaryTreeNode class])
    [self setVersion:0];	/* beta release */
  return self;
}

- init
{
  [super init];
  _left = _right = _parent = nil;
  return self;
}

- (void) encodeWithCoder: (Coder*)aCoder
{
  [super encodeWithCoder:aCoder];
  [aCoder encodeObjectReference:_right withName:"Right BinaryTree Node"];
  [aCoder encodeObjectReference:_left withName:"Left BinaryTree Node"];
  [aCoder encodeObjectReference:_parent withName:"Parent BinaryTree Node"];
}

+ newWithCoder: (Coder*)aCoder
{
  BinaryTreeNode *n = [super newWithCoder:aCoder];
  [aCoder decodeObjectAt:&(n->_right) withName:NULL];
  [aCoder decodeObjectAt:&(n->_left) withName:NULL];
  [aCoder decodeObjectAt:&(n->_parent) withName:NULL];
  return n;
}

- write: (TypedStream*)aStream
{
  [super write:aStream];
  objc_write_object_reference(aStream, _right);
  objc_write_object_reference(aStream, _left);
  objc_write_object_reference(aStream, _parent);
  return self;
}

- read: (TypedStream*)aStream
{
  [super read:aStream];
  objc_read_object(aStream, &_right);
  objc_read_object(aStream, &_left);
  objc_read_object(aStream, &_parent);
  return self;
}

- leftNode
{
  return _left;
}

- rightNode
{
  return _right;
}

- parentNode
{
  return _parent;
}

- setLeftNode: aNode
{
  _left = aNode;
  return self;
}

- setRightNode: aNode
{
  _right = aNode;
  return self;
}

- setParentNode: aNode
{
  _parent = aNode;
  return self;
}

@end

