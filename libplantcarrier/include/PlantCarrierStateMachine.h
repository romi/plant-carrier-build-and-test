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

#ifndef PLANT_CARRIER_BUILD_AND_TEST_PLANTCARRIERSTATEMACHINE_H
#define PLANT_CARRIER_BUILD_AND_TEST_PLANTCARRIERSTATEMACHINE_H


#include "WorkSession.h"
#include "api/StateMachine.h"

namespace plant_carrier {

    enum PlantCarrierStates {
        state_ready = 0,
        state_moving_to_plant,
        state_plant_lifting,
        state_moving_to_scanner,
        state_scanning,
        state_going_storrage,
        state_depositing,
        state_completing
    };

    enum PlantCarrierEvents {
        event_start = 1,
        event_found_april_tag,
        event_scan_ending,
        event_end_of_move
        // ...
    };

    class PlantCarrierStateMachine : public romi::StateMachine<WorkSession> {

        protected:
            void init_state_transitions(WorkSession& work_session);
            bool plant_carrier_activity(WorkSession& work_session);

        public:
            PlantCarrierStateMachine(WorkSession& work_session);
    };

}
#endif //PLANT_CARRIER_BUILD_AND_TEST_PLANTCARRIERSTATEMACHINE_H
