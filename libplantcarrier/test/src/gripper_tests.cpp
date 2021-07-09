/*
  Plant Carrier

  Copyright (C) 2019 Sony Computer Science Laboratories
  Author(s) Nicolas Branas, Peter Hanappe

  Plant Carrier is part of the ROMI PROJECT_NAME.

  Plant Carrier is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/>.

 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mock_cnc.h"
#include "Gripper.h"

using namespace std;
using namespace testing;
using namespace romi;


class gripper_tests : public ::testing::Test
{
protected:

	gripper_tests() {
        }

	~gripper_tests() override = default;

	void SetUp() override {
        }

	void TearDown() override {}
};

TEST_F(gripper_tests, can_construct)
{
        // Arrange
        MockCNC mock_cnc;

        // Act
        // Assert
        ASSERT_NO_THROW(plant_carrier::Gripper gripper(mock_cnc));
}

TEST_F(gripper_tests, pick_up_first_moveto_fails_returns_false)
{
    // Arrange
    MockCNC mock_cnc;
    EXPECT_CALL(mock_cnc, moveto)
            .WillOnce(Return(false));

    bool expected = false;
    plant_carrier::Gripper gripper(mock_cnc);

    // Act
    bool actual = gripper.pick_up();

    // Assert
    ASSERT_EQ(actual,expected);
}

TEST_F(gripper_tests, pick_up_second_moveto_fails_returns_false)
{
    // Arrange
    MockCNC mock_cnc;
    EXPECT_CALL(mock_cnc, moveto)
            .WillOnce(Return(true))
            .WillOnce(Return(false));

    bool expected = false;
    plant_carrier::Gripper gripper(mock_cnc);

    // Act
    bool actual = gripper.pick_up();

    // Assert
    ASSERT_EQ(actual,expected);
}

TEST_F(gripper_tests, put_down_first_moveto_fails_returns_false)
{
    // Arrange
    MockCNC mock_cnc;
    EXPECT_CALL(mock_cnc, moveto)
            .WillOnce(Return(false));

    bool expected = false;
    plant_carrier::Gripper gripper(mock_cnc);

    // Act
    bool actual = gripper.put_down();

    // Assert
    ASSERT_EQ(actual,expected);
}

TEST_F(gripper_tests, put_down_second_moveto_fails_returns_false)
{
    // Arrange
    MockCNC mock_cnc;
    EXPECT_CALL(mock_cnc, moveto)
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    bool expected = false;
    plant_carrier::Gripper gripper(mock_cnc);

    // Act
    bool actual = gripper.put_down();

    // Assert
    ASSERT_EQ(actual,expected);
}

TEST_F(gripper_tests, homing_fails_returns_false)
{
    // Arrange
    MockCNC mock_cnc;
    EXPECT_CALL(mock_cnc, homing)
            .WillOnce(Return(false));

    bool expected = false;
    plant_carrier::Gripper gripper(mock_cnc);

    // Act
    bool actual = gripper.homing();

    // Assert
    ASSERT_EQ(actual,expected);
}