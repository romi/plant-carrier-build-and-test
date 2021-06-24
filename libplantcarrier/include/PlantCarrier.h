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

namespace plant_carrier {

        class PlantCarrier : public IPlantCarrier {
        public:
            IGripper& gripper_;

            PlantCarrier(IGripper& gripper);
            ~PlantCarrier() override = default;
            int32_t demo_function(int32_t num1, int32_t num2) override;
        };

}
#endif // PLANTCARRIER_PLANTCARRIER_H
