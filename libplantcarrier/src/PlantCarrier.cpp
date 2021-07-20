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

#include "PlantCarrier.h"

namespace plant_carrier {

    PlantCarrier::PlantCarrier(IGripper& gripper, /*romi::StepperMotorDriver& IWheel& wheel*/ romi::INavigation& navigation)
        : gripper_(gripper), /*wheel_(wheel)*/navigation_(navigation)
    {
    }

    bool PlantCarrier::power_up()
    {
        return navigation_.enable_controller() && gripper_.power_up();
    }

    bool PlantCarrier::power_down()
    {
        return navigation_.enable_controller() && gripper_.power_down();
    }

    /*bool PlantCarrier::move_forward() {
        bool success = false;
        success = wheel_.moveat(1, 1, 0);
        return success;
    }

    bool PlantCarrier::turn_around() {
        bool success = false;
        success = wheel_.move(5000, static_cast<int16_t>(8 * 0.29 / 0.30 * 400), static_cast<int16_t>(- 8 * 0.29 / 0.30 * 400), 0);
        return success;
    }*/

}
