cmake_minimum_required(VERSION 3.10)
project(libplantcarrier)

set(libplantcarrier_VERSION_MAJOR 0)
set(libplantcarrier_VERSION_MINOR 1)


include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

set(SOURCES
        include/IPlantCarrierDemo.h
        include/PlantCarrierDemo.h
        src/PlantCarrierDemo.cpp)


add_library(plantcarrier SHARED ${SOURCES})

target_include_directories(plantcarrier
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(plantcarrier stdc++fs)
# Add dependent libs as necessary
#target_link_libraries(plantcarrier rpp rcompp-lite romi stdc++fs)

# Always add mock library as other projects could rely on them.
add_subdirectory(test/mocks)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()
