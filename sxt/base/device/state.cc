/** Proofs GPU - Space and Time's cryptographic proof algorithms on the CPU and GPU.
 *
 * Copyright 2023-present Space and Time Labs, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "sxt/base/device/state.h"

#include <cuda_runtime.h>

#include <string>

#include "sxt/base/error/panic.h"

namespace sxt::basdv {
//--------------------------------------------------------------------------------------------------
// set_device
//--------------------------------------------------------------------------------------------------
void set_device(int device) noexcept {
  auto rcode = cudaSetDevice(device);
  if (rcode != cudaSuccess) {
    baser::panic("cudaSetDevice failed: {}", cudaGetErrorString(rcode));
  }
}

//--------------------------------------------------------------------------------------------------
// get_device
//--------------------------------------------------------------------------------------------------
int get_device() noexcept {
  int device;
  auto rcode = cudaGetDevice(&device);
  if (rcode != cudaSuccess) {
    baser::panic("cudaGetDevice failed: {}", cudaGetErrorString(rcode));
  }
  return device;
}
} // namespace sxt::basdv
