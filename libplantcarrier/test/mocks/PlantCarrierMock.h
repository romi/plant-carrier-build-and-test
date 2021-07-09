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

#include "IPlantCarrier.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
namespace plant_imager_mocks {
        class PlantCarrierMock : public plant_carrier::IPlantCarrier {
        public:
            MOCK_METHOD(bool, move_forward, (), (override));
            MOCK_METHOD(bool, turn_around, (), (override));
            MOCK_METHOD(bool, pick_up, (), (override));
            MOCK_METHOD(bool, put_down, (), (override));
            MOCK_METHOD(bool, homing, (), (override));
        };
}
#pragma GCC diagnostic pop
