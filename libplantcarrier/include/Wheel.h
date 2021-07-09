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

#ifndef PLANT_CARRIER_BUILD_AND_TEST_WHEEL_H
#define PLANT_CARRIER_BUILD_AND_TEST_WHEEL_H

#include "api/ICNC.h"
#include "IWheel.h"

namespace plant_carrier
{
    class Wheel : public IWheel {

    protected:
        romi::ICNC& cnc_;

    public:
        Wheel(romi::ICNC& cnc);
        virtual ~Wheel() override;

        bool move_forward() override;
        bool turn_around() override;

    };
}


#endif //PLANT_CARRIER_BUILD_AND_TEST_WHEEL_H
