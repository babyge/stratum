/*
 * Copyright 2018 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef STRATUM_HAL_LIB_PHAL_ONLP_ONLP_WRAPPER_MOCK_H_
#define STRATUM_HAL_LIB_PHAL_ONLP_ONLP_WRAPPER_MOCK_H_

#include "stratum/hal/lib/phal/onlp/onlp_wrapper.h"
//FIXME remove when onlp_wrapper.h is stable
//#include "stratum/hal/lib/phal/onlp/onlp_wrapper_fake.h"
#include "gmock/gmock.h"
#include "stratum/glue/status/status.h"

namespace stratum {
namespace hal {
namespace phal {
namespace onlp {

class MockOnlpWrapper : public OnlpInterface {
 public:
  ~MockOnlpWrapper() override{};

  MOCK_CONST_METHOD1(GetOidInfo, ::util::StatusOr<OidInfo>(OnlpOid oid));
  MOCK_CONST_METHOD1(GetSfpInfo, ::util::StatusOr<SfpInfo>(OnlpOid oid));
  MOCK_CONST_METHOD1(GetFanInfo, ::util::StatusOr<FanInfo>(OnlpOid oid));
  MOCK_CONST_METHOD1(GetPsuInfo, ::util::StatusOr<PsuInfo>(OnlpOid oid));
  MOCK_CONST_METHOD0(GetSfpPresenceBitmap, ::util::StatusOr<OnlpPresentBitmap>());
  MOCK_CONST_METHOD1(GetSfpPresent, ::util::StatusOr<bool>(OnlpOid port));
  MOCK_CONST_METHOD0(GetSfpMaxPortNumber, ::util::StatusOr<OnlpPortNumber>());
  MOCK_CONST_METHOD1(GetOidList, ::util::StatusOr<std::vector<OnlpOid>>(
        onlp_oid_type_flag_t type));
};

}  // namespace onlp
}  // namespace phal
}  // namespace hal
}  // namespace stratum
#endif  // STRATUM_HAL_LIB_PHAL_ONLP_ONLP_WRAPPER_MOCK_H_
