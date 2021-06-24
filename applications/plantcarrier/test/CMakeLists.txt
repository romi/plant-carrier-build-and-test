cmake_minimum_required(VERSION 3.10)

include_directories(mocks
        support)

set(SRCS
        src/tests_main.cpp
        )

add_executable(plant-carrier-example_unit_tests ${SRCS})

target_link_libraries(  plant-carrier-example_unit_tests
                        gtest
                        gmock
                        rpp
                        plantcarrier
                        stdc++fs)

add_test(
        NAME plant-carrier-example_unit_tests
        COMMAND plant-carrier-example_unit_tests
        )
