cmake_minimum_required(VERSION 3.10)

set(CARRIERSOURCES
        src/tests_main.cpp
        src/PlantCarrier_tests.cpp
        src/gripper_tests.cpp
        )

add_executable( libplantcarrier_unit_tests
                ${CARRIERSOURCES})

target_link_libraries( libplantcarrier_unit_tests
                        gtest
                        gmock
                        plantcarrier
                        plantcarrier-mocks)

add_test(
    NAME libplantcarrier_unit_tests
    COMMAND libplantcarrier_unit_tests
)

if(BUILD_COVERAGE)
    SETUP_TARGET_FOR_COVERAGE_LCOV(
            NAME libplantcarrier_unit_tests_coverage
            EXECUTABLE ctest -V ${n_cores} -R "libplantcarrier_"
            EXCLUDE '*wrapper*' "src/Linux.cpp" "include/*.h"
            DEPENDENCIES libplantcarrier_unit_tests)
endif()
