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
#ifndef PLANTCARRIER_GRIPPER_H
#define PLANTCARRIER_GRIPPER_H

#include "api/ICNC.h"
#include "IGripper.h"

namespace plant_carrier
{
    class Gripper : public IGripper {
    public:
        static constexpr double kXTravelDistance = 0.02;
        static constexpr double kZTravelDistance = 0.20;
        static constexpr double kXTravelSpeed = 0.1;
        static constexpr double kZTravelSpeed = 0.7;

    protected:
        romi::ICNC& cnc_;

    public:
        Gripper(romi::ICNC& cnc);
        virtual ~Gripper() override = default;
        
        bool pick_up() override;
        bool put_down() override;
        bool homing() override;
    };
}

#endif // PLANTCARRIER_GRIPPER_H