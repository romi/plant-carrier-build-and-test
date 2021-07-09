project(plant-carrier-mocks)

#
set(SOURCES
        PlantCarrierDemoMock.h
        GripperMock.h
        )

add_library(plantcarrier-mocks SHARED ${SOURCES})
set_target_properties(plantcarrier-mocks PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(plantcarrier-mocks
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}
        )