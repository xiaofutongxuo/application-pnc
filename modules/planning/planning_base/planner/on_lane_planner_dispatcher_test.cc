/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 **/

#include "modules/planning/planning_base/planner/on_lane_planner_dispatcher.h"

#include "gtest/gtest.h"
#include "cyber/common/file.h"
#include "modules/planning/planning_base/common/dependency_injector.h"
#include "modules/planning/planning_base/planner/planner_dispatcher.h"

namespace apollo {
namespace planning {

class OnLanePlannerDispatcherTest : public ::testing::Test {
 public:
  virtual void SetUp() {}

 protected:
  std::unique_ptr<PlannerDispatcher> pd_;
};

TEST_F(OnLanePlannerDispatcherTest, Simple) {
  auto injector = std::make_shared<DependencyInjector>();
  pd_.reset(new OnLanePlannerDispatcher());
  pd_->Init();

  const std::string planning_config_file =
      "/apollo/modules/planning/planning_base/conf/planning_config.pb.txt";
  PlanningConfig planning_config;
  apollo::cyber::common::GetProtoFromFile(planning_config_file,
                                          &planning_config);
  auto planner = pd_->DispatchPlanner(planning_config, injector);

  EXPECT_EQ(planner->Name(), "PUBLIC_ROAD");
}

}  // namespace planning
}  // namespace apollo
