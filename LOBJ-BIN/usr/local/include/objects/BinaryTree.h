/* Interface for Objective-C BinaryTree collection object
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

/* 
   Binary Tree.  
   Base class for smarter binary trees.
*/

#ifndef __BinaryTree_h_INCLUDE_GNU
#define __BinaryTree_h_INCLUDE_GNU

#include <objects/stdobjects.h>
#include <objects/IndexedCollection.h>

/* The <BinaryTreeComprising> protocol defines the interface to an object
   that may be an element in a BinaryTree. 
*/
@protocol BinaryTreeComprising
- leftNode;
- rightNode;
- parentNode;
- setLeftNode: (id <BinaryTreeComprising>)aNode;
- setRightNode: (id <BinaryTreeComprising>)aNode;
- setParentNode: (id <BinaryTreeComprising>)aNode;
@end

#define NODE_IS_RIGHTCHILD(NODE) (NODE == [[NODE parentNode] rightNode])
#define NODE_IS_LEFTCHILD(NODE) (NODE == [[NODE parentNode] leftNode])

@interface BinaryTree : IndexedCollection
{
  unsigned int _count;
  id _contents_root;
}

- nilNode;
- rootNode;

- leftmostNodeFromNode: aNode;
- rightmostNodeFromNode: aNode;

- (unsigned) depthOfNode: aNode;
- (unsigned) heightOfNode: aNode;

- (unsigned) nodeCountUnderNode: aNode;

- leftRotateAroundNode: aNode;
- rightRotateAroundNode: aNode;

- binaryTreePrintForDebugger;

@end


#endif /* __BinaryTree_h_INCLUDE_GNU */
