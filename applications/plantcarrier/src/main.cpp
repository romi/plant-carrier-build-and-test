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

#include <mock_session.h>

// LCOV_EXCL_START

/*romi::Session create_session(){
    romi::IRomiDeviceData &device_data();
    romi::ISoftwareVersion &softwareVersion();
    romi::Gps gps();
    std::shared_ptr<GpsLocationProvider>(gps) location;
    romi::Session session(rpp::Linux(),"Desktop/test",device_data,softwareVersion,location);
}

romi::Oquam create_oquam()
{

    //controller creation
    auto romi_serial = romiserial::RomiSerialClient::create("/dev/ttyACM0");
    romi::StepperController controller(romi_serial);

    //settings creation
    double xmin[] = { 0.0, 0.0, 0.0 };
    double xmax[] = { 0.0, 0.030, 0.24 };
    romi::CNCRange range(xmin, xmax);
    double vmax[] = { 0.0, 0.10, 0.00375 };
    double amax[] = { 0.0, 0.40, 0.0015 };
    double scale_meters_to_steps[] = { 0.0, 200.0 * 8.0 / 0.060, 200.0 *1.0  / 0.0015 };
    romi::AxisIndex axis_homing[] = { romi::AxisIndex::kNoAxis, romi::AxisIndex::kAxisY, romi::AxisIndex::kNoAxis };
    romi::OquamSettings settings(range, vmax, amax, scale_meters_to_steps, 0.0, 0.010, 1.0, axis_homing);

    //session creation
    romi::Session session = create_session();

    romi::Oquam cnc(controller, settings, session);
    return cnc;
}

plant_carrier::Gripper create_gripper()
{
    romi::Oquam cnc = create_oquam();
    plant_carrier::Gripper gripper(cnc);
    return gripper;
}

plant_carrier::PlantCarrier create_plant_carrier()
{
    plant_carrier::GripperMock gripper;// = create_gripper();
    plant_carrier::PlantCarrier plantcarrier(gripper);
    return plantcarrier;
}*/

int main()
{
    //plant_carrier::PlantCarrier plantcarrier = create_plant_carrier();

//controller creation
    auto romi_serial = romiserial::RomiSerialClient::create("/dev/ttyACM1");//!!!!!Il faut rajouter une verification de connection, sinon les "write" dans le port serie ne s'executent pas et ne renvoient pas d'erreur
    romi::StepperController controller(romi_serial);

//settings creation
    double xmin[] = { 0.0, 0.0, 0.0 };
    double xmax[] = { 0.03, 0.0, 0.24 };
    romi::CNCRange range(xmin, xmax);
    double vmax[] = { 0.10, 0.0, 0.00375 };
    double amax[] = { 0.40, 0.1, 0.0015 };//!!!!! Un zero entraine une division par zero!!!!! d'ou le 0.1
    double scale_meters_to_steps[] = { 200.0 * 8.0 / 0.060, 1.0, 200.0 * 1.0  / 0.0015 }; //!!!!! Un zero entraine une division par zero!!!!! d'ou le 1.0
    romi::AxisIndex axis_homing[] = { romi::AxisIndex::kAxisX, romi::AxisIndex::kNoAxis, romi::AxisIndex::kNoAxis };
    romi::OquamSettings settings(range, vmax, amax, scale_meters_to_steps, 0.0, 0.010, 1.0, axis_homing);

//session creation
    //MockSession session;
    const rpp::Linux linux;
    const std::string base_directory ="Desktop/test";
    romi::RomiDeviceData device_data;
    romi::SoftwareVersion software_version;
    romi::Gps gps;
    //std::shared_ptr<romi::GpsLocationProvider> location;
    auto location = std::make_shared<romi::GpsLocationProvider>(gps);
    romi::Session session(linux,base_directory,device_data,software_version,location);

//Oquam cnc creation
    romi::Oquam cnc(controller, settings, session);

//Gripper creation
    plant_carrier::Gripper gripper(cnc);

//PlantCarrier creation
    plant_carrier::PlantCarrier plantcarrier(gripper);

//Control begin
    plantcarrier.gripper_.homing();
    //plantcarrier.gripper_.pick_up();
    //plantcarrier.gripper_.put_down();



    //auto result = plantcarrier.demo_function(1, 2);
    //std::cout << "Result: " << result << std::endl;

    return 0;
}

// LCOV_EXCL_END