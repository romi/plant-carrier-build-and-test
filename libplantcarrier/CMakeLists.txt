cmake_minimum_required(VERSION 3.10)
project(libplantcarrier)

set(libplantcarrier_VERSION_MAJOR 0)
set(libplantcarrier_VERSION_MINOR 1)


include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

set(SOURCES
    include/Gripper.h
    include/IGripper.h
    include/IPlantCarrier.h
    include/IPlantCarrierDemo.h
    include/IScanner.h
    include/IWheel.h
    include/PlantCarrier.h
    include/PlantCarrierDemo.h
    include/PlantCarrierStateMachine.h
    include/Scanner.h
    include/StepperMotorDriver.h
    include/Wheel.h
    src/Gripper.cpp
    src/PlantCarrier.cpp
    src/PlantCarrierDemo.cpp
    src/PlantCarrierStateMachine.cpp
    src/Scanner.cpp
    src/StepperMotorDriver.cpp
    src/Wheel.cpp include/IWorkSession.h include/WorkSession.cpp include/WorkSession.h)


add_library(plantcarrier SHARED ${SOURCES})

target_include_directories(plantcarrier
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

target_link_libraries(plantcarrier romi romimocks stdc++fs)
# Add dependent libs as necessary
#target_link_libraries(plantcarrier rpp rcompp-lite romi stdc++fs)

# Always add mock library as other projects could rely on them.
add_subdirectory(test/mocks)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()
