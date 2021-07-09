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

#ifndef PLANTCARRIER_IPLANTCARRIER_H
#define PLANTCARRIER_IPLANTCARRIER_H

#include <cstdint>
namespace plant_carrier
{
    class IPlantCarrier {
        public:
            IPlantCarrier() = default;
            virtual ~IPlantCarrier() = default;

            virtual bool move_forward() = 0;
            virtual bool turn_around() = 0;

            virtual bool pick_up() = 0;
            virtual bool put_down() = 0;

            virtual bool homing() = 0;
    };

}
#endif // PLANTCARRIER_IPLANTCARRIER_H
