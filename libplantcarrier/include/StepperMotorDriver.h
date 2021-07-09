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

#ifndef PLANT_CARRIER_BUILD_AND_TEST_STEPPERMOTORDRIVER_H
#define PLANT_CARRIER_BUILD_AND_TEST_STEPPERMOTORDRIVER_H

#include <stdexcept>
#include <memory>
#include <atomic>
#include <thread>
#include "hal/BrushMotorDriver.h"
#include "RomiSerialClient.h"
#include "api/ICNC.h"
#include "oquam/StepperController.h"

namespace romi {

    class StepperMotorDriver : public IMotorDriver
    {

        protected:
            romi::StepperController& controller_;
            //std::unique_ptr<romiserial::IRomiSerialClient>& serial_;

        public:

            StepperMotorDriver(romi::StepperController& controller);
            ~StepperMotorDriver() override;

            bool moveat(double x_speed, double y_speed, double z_speed);
            bool moveat(double gauche, double droite) override;

            bool move(int16_t millis, int16_t steps_x,int16_t steps_y, int16_t steps_z);

            bool stop() override;

            bool get_encoder_values(double& left, double& right, double& timestamp) override;

            bool get_pid_values(Axis axis, double& target_speed, double& measured_speed,
                                double& pid_output, double& pid_error_p, double& pid_error_i,
                                double& pid_error_d, double& controller_input) override;

        protected:

            bool check_response(const char *command, JsonCpp& response);

    };
}

#endif //PLANT_CARRIER_BUILD_AND_TEST_STEPPERMOTORDRIVER_H
