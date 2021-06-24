cmake_minimum_required(VERSION 3.10)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(plant-carrier
                src/main.cpp
        )

target_link_libraries(plant-carrier
                        rpp
                        romi
                        gmock
                        gtest
                        romimocks
                        plantcarrier
                        stdc++fs)

# Add dependent libs as necessary
#target_link_libraries(plant-carrier
#        rpp
#        rcompp-lite
#        romi
#        plant-imager
#        stdc++fs)

if (BUILD_TESTS)
    add_subdirectory(test)
endif()
