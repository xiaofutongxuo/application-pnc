/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <fstream>

#include "modules/planning/planning_base/common/planning_gflags.h"

namespace apollo {
namespace planning {

class EvaluatorLogger {
 public:
  static std::ofstream& GetStream() {
    static std::ofstream log_file(
        FLAGS_planning_data_dir + "/output_data_evaluated.log",
        std::ios_base::out | std::ios_base::app);
    return log_file;
  }
};

}  // namespace planning
}  // namespace apollo
