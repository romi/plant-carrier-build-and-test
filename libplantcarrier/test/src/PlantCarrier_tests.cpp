#include <string>
#include "gtest/gtest.h"
#include "PlantCarrier.h"
#include <PlantCarrierMock.h>

using ::testing::_;
using ::testing::Return;


#include "GripperMock.h"

class plant_imager_tests : public ::testing::Test
{
protected:
    plant_carrier_mocks::GripperMock gripper_;

    plant_imager_tests() : gripper_() {
    }

    ~plant_imager_tests() override = default;

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

};

TEST_F(plant_imager_tests, plant_imager_result_is_correct)
{
        // Arrange;
        const int32_t num1 = 1;
        const int32_t num2 = 2;
        int expected = num1 + num2;
        plant_carrier::PlantCarrier plantcarrier(gripper_);

        // Act
        auto actual = plantcarrier.demo_function(num1, num2);

        // Assert
        ASSERT_EQ(actual, expected);
}


