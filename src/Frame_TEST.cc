/*
 * Copyright (C) 2018 Open Source Robotics Foundation
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
 *
*/

#include <gtest/gtest.h>
#include "sdf/Frame.hh"
#include "sdf/Geometry.hh"

/////////////////////////////////////////////////
TEST(DOMframe, Construction)
{
  sdf::Frame frame;
  EXPECT_EQ(nullptr, frame.Element());
  EXPECT_TRUE(frame.Name().empty());

  frame.SetName("test_frame");
  EXPECT_EQ(frame.Name(), "test_frame");

  EXPECT_TRUE(frame.AttachedTo().empty());
  EXPECT_EQ(ignition::math::Pose3d::Zero, frame.RawPose());
  EXPECT_TRUE(frame.PoseRelativeTo().empty());

  frame.SetAttachedTo("attachment");
  EXPECT_EQ("attachment", frame.AttachedTo());

  frame.SetRawPose({-10, -20, -30, IGN_PI, IGN_PI, IGN_PI});
  EXPECT_EQ(ignition::math::Pose3d(-10, -20, -30, IGN_PI, IGN_PI, IGN_PI),
            frame.RawPose());

  frame.SetPoseRelativeTo("link");
  EXPECT_EQ("link", frame.PoseRelativeTo());
}
