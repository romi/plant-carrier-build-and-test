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