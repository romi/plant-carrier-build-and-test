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

#include <string>
#include "gtest/gtest.h"
#include "PlantCarrier.h"
#include <PlantCarrierMock.h>

using ::testing::_;
using ::testing::Return;


#include "GripperMock.h"
#include "WheelMock.h"

class plant_imager_tests : public ::testing::Test
{
protected:
    //plant_carrier_mocks::GripperMock gripper_;
    //plant_carrier_mocks::WheelMock wheel_;

    /*plant_imager_tests() : gripper_(), wheel_() {
    }

    ~plant_imager_tests() override = default;*/

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

};

/*TEST_F(plant_imager_tests, plant_imager_result_is_correct)
{
        // Arrange;
        const int32_t num1 = 1;
        const int32_t num2 = 2;
        int expected = num1 + num2;
        plant_carrier::PlantCarrier plantcarrier(gripper_,wheel_);

        // Act
        auto actual = plantcarrier.demo_function(num1, num2);

        // Assert
        ASSERT_EQ(actual, expected);
}*/


