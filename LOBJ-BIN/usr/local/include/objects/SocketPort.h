/* Interface for socket-based port object for use with Connection
   Copyright (C) 1994 Free Software Foundation, Inc.
   
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

#ifndef __SocketPort_h_INCLUDE_GNU
#define __SocketPort_h_INCLUDE_GNU

#include <objects/stdobjects.h>
#include <objects/Port.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct sockaddr_in sockport_t;

@interface SocketPort : Port
{
  sockport_t sockPort;
  int sock;			/* socket if local, 0 if remote */
  BOOL close_on_dealloc;
}


+ newForSockPort: (sockport_t)s close: (BOOL)f;
+ newForSockPort: (sockport_t)s;
+ newLocalWithNumber: (int)n;
+ newLocal;
+ newRemoteWithNumber: (int)n onHost: (const char*)h;

- (sockport_t) sockPort;

- (int) socket;
- (int) socketPortNumber;

@end

#endif /* __SocketPort_h_INCLUDE_GNU */
