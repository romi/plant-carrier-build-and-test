#include <iostream>

#include <PlantCarrier.h>
#include <RSerial.h>
#include <RomiSerialClient.h>
#include <api/CNCRange.h>
#include <oquam/StepperController.h>
#include <oquam/Oquam.h>
#include <data_provider/RomiDeviceData.h>
#include <data_provider/SoftwareVersion.h>
#include <data_provider/Gps.h>
#include <data_provider/GpsLocationProvider.h>
#include <session/Session.h>
#include <Linux.h>
#include <Gripper.h>
#include <rover/NavigationSettings.h>
#include "Wheel.h"
#include "rover/LocationTracker.h"
#include "rover/WheelOdometry.h"
#include "rover/ZeroNavigationController.h"
#include "rover/Navigation.h"
#include "camera/USBCamera.h"
#include "cv/ImageIO.h"
//#include "PlantCarrierStateMachine.h"
//#include "picamera/PiCameraSettings.h"
//#include "picamera/PiCamera.h"

#include <mock_session.h>
#include <camera/FileCamera.h>

// LCOV_EXCL_START

int main()
{
/*
//Controllers creation
    const std::string pincer("/dev/ttyACM2");
    const std::string wheels("/dev/ttyACM1");

    auto gripper_serial = romiserial::RomiSerialClient::create(pincer.c_str());//!!!!!Il faut rajouter une verification de connection, sinon les "write" dans le port serie ne s'executent pas et ne renvoient pas d'erreur
    auto wheel_serial = romiserial::RomiSerialClient::create(wheels.c_str());//!!!!!Il faut rajouter une verification de connection, sinon les "write" dans le port serie ne s'executent pas et ne renvoient pas d'erreur

    romi::StepperController grip_controller(gripper_serial);
    romi::StepperController wheel_controller(wheel_serial);

//session creation
    const rpp::Linux linux;
    const std::string base_directory ="Desktop/test";
    romi::RomiDeviceData device_data;
    romi::SoftwareVersion software_version;
    romi::Gps gps;
    auto location = std::make_shared<romi::GpsLocationProvider>(gps);
    romi::Session session(linux,base_directory,device_data,software_version,location);

//settings creation
    double grip_xmin[] = { 0.0, 0.0, 0.0 };
    double grip_xmax[] = { 0.03, 0.0, 0.16 };
    romi::CNCRange grip_range(grip_xmin, grip_xmax);
    double grip_vmax[] = { 0.10, 0.0, 0.10 };
    double grip_amax[] = { 0.40, 0.1, 0.10 };//!!!!! Un zero entraine une division par zero!!!!! d'ou le 0.1
    double grip_scale_meters_to_steps[] = { 200.0 * 8.0 / 0.060, 1.0, 200.0 * 2.0  / 0.032 }; //!!!!! Un zero entraine une division par zero!!!!! d'ou le 1.0
    romi::AxisIndex grip_axis_homing[] = { romi::AxisIndex::kAxisX, romi::AxisIndex::kNoAxis, romi::AxisIndex::kNoAxis };
    romi::OquamSettings grip_oquam_settings(grip_range, grip_vmax, grip_amax, grip_scale_meters_to_steps, 0.0, 0.010, 1.0, grip_axis_homing);

    double wheel_xmin[] = { -99999, -99999, 0.0 };
    double wheel_xmax[] = { 99999, 99999, 0.0 };
    romi::CNCRange wheel_range(wheel_xmin, wheel_xmax);
    double wheel_vmax[] = { 1., 1., 0.0 };
    double wheel_amax[] = { 0.2, 0.2, 0.10 };//!!!!! Un zero entraine une division par zero!!!!! d'ou le 0.1
    double wheel_scale_meters_to_steps[] = { 400.0 * 8.0 / (M_PI*0.145), 400.0 * 8.0 / (M_PI*0.145), 1 }; //!!!!! Un zero entraine une division par zero!!!!! d'ou le 1.0
    romi::AxisIndex wheel_axis_homing[] = { romi::AxisIndex::kNoAxis, romi::AxisIndex::kNoAxis, romi::AxisIndex::kNoAxis };
    romi::OquamSettings wheel_oquam_settings(wheel_range, wheel_vmax, wheel_amax, wheel_scale_meters_to_steps, 0.0, 0.010, 1.0, wheel_axis_homing);

//Gripper creation
    romi::Oquam grip_cnc(grip_controller, grip_oquam_settings, session);
    plant_carrier::Gripper gripper(grip_cnc);

//Wheel creation
    //romi::Oquam wheel_cnc(wheel_controller, wheel_oquam_settings, session);
    //romi::StepperMotorDriver wheel (wheel_cnc);
    //plant_carrier::Wheel wheel (wheel_cnc);

//PlantCarrier creation
    //plant_carrier::PlantCarrier plant_carrier(gripper,wheel);

//Navigation setting
    JsonCpp config = JsonCpp::parse("{"
                                    "'wheel-diameter': 0.15,"
                                    "'wheel-base': 0.25,"
                                    "'encoder-steps': 3200,"
                                    "'maximum-speed': 1, "
                                    "'maximum-acceleration': 0.5 }");

    romi::NavigationSettings nav_settings(config);
    romi::StepperMotorDriver driver(wheel_controller);
    romi::WheelOdometry wheel_odometry(nav_settings,driver);
    romi::LocationTracker distance_measure(wheel_odometry,wheel_odometry);
    romi::ZeroNavigationController nav_controller;

    romi::Navigation navigation (nav_settings,driver,distance_measure,distance_measure,nav_controller,session); //Parfois il faut reset les ports

    plant_carrier::PlantCarrier plant_carrier(gripper,navigation);
    plant_carrier.power_up();

//    plant_carrier::PlantCarrierStateMachine plant_carrier_SM (plant_carrier);


//Control begin
//    plant_carrier.homing();
//    plant_carrier.pick_up();
//    plant_carrier.put_down();
//    plant_carrier.move_forward();
//    plant_carrier.turn_around();

//    navigation.move(1,0.5);

*/
/*
    romi::USBCamera camera0 ("/dev/video0",640,480);

    romi::Image image0;

    camera0.grab(image0);
    romi::ImageIO::store_jpg(image0, "/home/nicolasbranas/Desktop/image.jpg");
    romi::ImageIO::store_png(image0, "/home/nicolasbranas/Desktop/image.png"); //pas de rouge?
*/
   /* auto start = std::chrono::system_clock::now();
    try {
        romi::V2CameraSettings settings(640, 480);
        romi::PiCamera camera(settings);
        romi::Image image;
        for (int i = 0; i < 60; i++) {
            camera.grab(image);
            r_debug("image %d", i);
        }
    } catch (std::exception& e) {
        r_err("Caught exception: %s", e.what());
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << elapsed.count() << '\n';*/

//ImageIO jpg:photo, png: sans perte (masques)

    return 0;
}

// LCOV_EXCL_END
