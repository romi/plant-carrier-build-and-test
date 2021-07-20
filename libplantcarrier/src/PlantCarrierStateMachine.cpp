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

#include "PlantCarrierStateMachine.h"
#include <iostream>

namespace plant_carrier {

    PlantCarrierStateMachine::PlantCarrierStateMachine(WorkSession& work_session): StateMachine<WorkSession>(work_session)
    {
        init_state_transitions(work_session);
    }

    bool lift_plant(WorkSession& work_session) { return work_session.get_pc().pick_up(); }
    bool follow_the_line(WorkSession& work_session) { return work_session.get_pc().move_forward(); }
    bool scan(WorkSession& work_session) { return work_session.get_pc().move_forward(); }
    bool deposit_plant(WorkSession& work_session) { return work_session.get_pc().put_down(); }
    bool power_down(WorkSession& work_session) { return work_session.get_pc().power_down(); }

    /*bool plant_carrier_activity(WorkSession& work_session)
    {
        int index = 1;
        while (index <= work_session.get_plant_number()){
            try {
                PlantCarrierStateMachine::StateMachine::add(state_moving_to_plant, event_found_april_tag, lift_plant, state_plant_lifting);
                add(state_plant_lifting, event_end_of_move, follow_the_line, state_moving_to_scanner);
                add(state_moving_to_scanner, event_found_april_tag, scan, state_scanning);
                add(state_scanning, event_scan_ending, follow_the_line, state_going_storrage);
                add(state_going_storrage, event_found_april_tag, deposit_plant, state_depositing);
                add(state_depositing, event_end_of_move, follow_the_line, state_moving_to_plant);
            }
            catch (const std::exception& ex){
                std::cout<<ex.what();
                throw(ex);
            }
        }

        add(ALL_STATES, event_found_april_tag, power_down, state_completing);
        return true;
    }*/

    bool initialize_plant_carrier(WorkSession& work_session)
    {
        if (!work_session.get_pc().power_up()){
            r_debug("Plant carrier power up fail");
            return false;
        }
        return true;
        //return plant_carrier_activity(work_session);
    }

    void PlantCarrierStateMachine::init_state_transitions(WorkSession& work_session)
    {
        add(STATE_START, event_start, initialize_plant_carrier, state_ready);
        add(STATE_START, state_ready, follow_the_line, state_moving_to_plant);

        int index = 1;
        while (index <= work_session.get_plant_number()){
            try {
                PlantCarrierStateMachine::StateMachine::add(state_moving_to_plant, event_found_april_tag, lift_plant, state_plant_lifting);
                add(state_plant_lifting, event_end_of_move, follow_the_line, state_moving_to_scanner);
                add(state_moving_to_scanner, event_found_april_tag, scan, state_scanning);
                add(state_scanning, event_scan_ending, follow_the_line, state_going_storrage);
                add(state_going_storrage, event_found_april_tag, deposit_plant, state_depositing);
                add(state_depositing, event_end_of_move, follow_the_line, state_moving_to_plant);
            }
            catch (const std::exception& ex){
                std::cout<<ex.what();
                throw(ex);
            }
        }

        add(ALL_STATES, event_found_april_tag, power_down, state_completing);

//        add(ALL_STATES,
//            event_system_failure,
//            signal_system_failure,
//            state_system_failure);
    }
}