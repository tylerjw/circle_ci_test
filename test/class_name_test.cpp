/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2020, PickNik Inc
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of PickNik Inc nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Tyler Weaver
   Desc: TODO(tylerjw):
*/

// clang-format off
/** EXAMPLES:
    EXPECT_FALSE(robot_state.hasFixedLinks());
    EXPECT_EQ(robot_state.getFixedLinksCount(), 0);
    EXPECT_TRUE(robot_state.getPrimaryFixedLink() == NULL);
    EXPECT_GT(robot_state.getFixedLinksMode(), 0);
    EXPECT_LT( fabs(vars[0] - 0), EPSILON) << "Virtual joint in wrong position " << vars[0];
*/
// clang-format on

// C++
#include <string>

// ROS
#include <ros/ros.h>

// Testing
#include <gtest/gtest.h>

// Main class
#include <ci_test/class_name.h>

namespace ci_test
{
class TestClassName : public ::testing::Test
{
public:
  void SetUp() override
  {
    nh_.reset(new ros::NodeHandle("~"));
    server_.reset(new ClassName());
  }
  void TearDown() override
  {
  }

protected:
  std::unique_ptr<ros::NodeHandle> nh_;
  ClassNamePtr server_;
};  // class TestClassName

TEST_F(TestClassName, TestNameOfClass)
{
  // ClassName no longer has a name_ value
  ASSERT_TRUE(true);
}

}  // namespace ci_test

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "class_name_test");

  ros::AsyncSpinner spinner(1);
  spinner.start();

  int result = RUN_ALL_TESTS();

  spinner.stop();
  ros::shutdown();
  return result;
}
