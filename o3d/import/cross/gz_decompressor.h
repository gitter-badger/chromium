/*
 * Copyright 2009, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//
// GzDecompressor decompresses a gzip compressed byte stream
// calling the client's ProcessBytes() method with the uncompressed stream
//

#ifndef O3D_IMPORT_CROSS_GZ_DECOMPRESSOR_H_
#define O3D_IMPORT_CROSS_GZ_DECOMPRESSOR_H_

#include "base/basictypes.h"
#include "zlib.h"
#include "import/cross/memory_stream.h"

namespace o3d {

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class GzDecompressor : public StreamProcessor {
 public:
  explicit GzDecompressor(StreamProcessor *callback_client);
  virtual ~GzDecompressor();

  virtual int     ProcessBytes(MemoryReadStream *stream,
                               size_t bytes_to_process);

 private:
  z_stream         strm_;  // low-level zlib state
  int              init_result_;
  StreamProcessor  *callback_client_;

  DISALLOW_COPY_AND_ASSIGN(GzDecompressor);
};

}  // namespace o3d

#endif  //  O3D_IMPORT_CROSS_GZ_DECOMPRESSOR_H_
