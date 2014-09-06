/*****************************************************************************\
  Processor.h : Interface for the Processor class

  Copyright (c) 1996 - 2001, Hewlett-Packard Co.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
  3. Neither the name of Hewlett-Packard nor the names of its
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
  NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
  TO, PATENT INFRINGEMENT; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\*****************************************************************************/

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "CommonDefinitions.h"
class Pipeline;
class Processor
{
public:
    Processor();
    virtual ~Processor();
    //virtual bool Process(BYTE* InputRaster=NULL, unsigned int size=0)=0;    // returns TRUE iff output ready
    virtual bool Process(RASTERDATA  *InputRaster=NULL)=0;    // returns TRUE iff output ready
    virtual void Flush()=0;     // take any concluding actions based on internal state
    virtual bool NextOutputRaster(RASTERDATA& next_raster)=0;
    virtual unsigned int GetMaxOutputWidth() = 0;// in bytes, not pixels

    unsigned int iRastersReady, iRastersDelivered;
    Pipeline* myphase;
    COLORTYPE myplane;
    RASTERDATA  raster;
}; // Processor

#endif // PROCESSOR_H

