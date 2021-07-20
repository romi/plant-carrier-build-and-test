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

#include <functional>
#include <util.h>
#include "StepperMotorDriver.h"
#include "oquam/Oquam.h"
#include <cmath>
#include <iostream>

namespace romi {

    StepperMotorDriver::StepperMotorDriver(romi::StepperController& controller)
                                            : controller_(controller)
    {
        //controller_.enable();
    }

    //StepperMotorDriver::~StepperMotorDriver(){}


    bool StepperMotorDriver::moveat(double gauche, double droite){
        std::cout<<"gauche = "<<gauche<<std::endl;
        return moveat(gauche, droite, 0);
    }

    bool StepperMotorDriver::moveat(double x_speed, double y_speed, double z_speed)
    {
        bool success = false;
        int16_t x_step_speed = (int16_t)(8*400*x_speed/(M_PI*0.15));
        std::cout<<"x_step_speed = "<< x_step_speed<<std::endl;
        int16_t y_step_speed = (int16_t)(8*400*y_speed/(M_PI*0.15));
        int16_t z_step_speed = (int16_t)(0 * z_speed);
        success = controller_.moveat(x_step_speed, y_step_speed, z_step_speed);
        return success;
    }

    bool StepperMotorDriver::stop()
    {
        return controller_.stop();
    }

    bool StepperMotorDriver::get_encoder_values(double& left, double& right, double& timestamp)
    {
        int32_t pos [3] = {0,0,0};
        bool success = controller_.get_position(pos);

        left = pos[0];
        right = pos[1];
        timestamp = pos[2];

        return success;
    }

    bool StepperMotorDriver::get_pid_values(Axis axis, double& target_speed, double& measured_speed,
                        double& pid_output, double& pid_error_p, double& pid_error_i,
                        double& pid_error_d, double& controller_input)
    {
        if (axis==kLeftWheel) target_speed=0;
        target_speed=0; measured_speed=0; pid_output=0; pid_error_p=0; pid_error_i=0; pid_error_d=0; controller_input=0;
        return false;
    }

    bool StepperMotorDriver::move(int16_t millis, int16_t steps_x, int16_t steps_y, int16_t steps_z) {
        return controller_.move(millis, steps_x, steps_y, steps_z);
    }

    bool StepperMotorDriver::disable_controller() {
        return controller_.disable();
    }

    bool StepperMotorDriver::enable_controller() {
        return controller_.enable();;
    }

}