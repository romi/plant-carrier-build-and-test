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
#ifndef PLANTCARRIER_PLANTCARRIER_H
#define PLANTCARRIER_PLANTCARRIER_H

#include "IPlantCarrier.h"
#include "IGripper.h"
#include "IWheel.h"
#include "StepperMotorDriver.h"

namespace plant_carrier {

        class PlantCarrier : public IPlantCarrier {

        protected:
            IGripper& gripper_;
            //romi::StepperMotorDriver& wheel_;
            IWheel& wheel_;

        public:
            PlantCarrier(IGripper& gripper, /*romi::StepperMotorDriver&*/IWheel& wheel);
            ~PlantCarrier() override = default;

            bool move_forward() override { return wheel_.move_forward(); }
            bool turn_around() override { return wheel_.turn_around(); }

            bool pick_up() override { return gripper_.pick_up(); }
            bool put_down() override { return gripper_.put_down(); }
            bool homing() override { return gripper_.homing(); }

        };

}
#endif // PLANTCARRIER_PLANTCARRIER_H
