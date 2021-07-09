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

#include "Wheel.h"

plant_carrier::Wheel::Wheel(romi::ICNC &cnc) : cnc_(cnc)
{
    cnc_.power_up();
}

plant_carrier::Wheel::~Wheel()
{
    cnc_.power_down();
}

bool plant_carrier::Wheel::move_forward() {
    bool success = false;
    success = cnc_.moveat(1000, 1000, 0);
    return success;
}

bool plant_carrier::Wheel::turn_around() {
    bool success = false;
    success = cnc_.moveto(-0.29*M_PI/2, 0.29*M_PI/2, 0, 0.2);
    return success;
}
