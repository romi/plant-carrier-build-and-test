#include "IGripper.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
namespace plant_carrier_mocks {
        class GripperMock : public plant_carrier::IGripper {
        public:
            MOCK_METHOD(bool, pick_up, (), (override));
            MOCK_METHOD(bool, put_down, (), (override));
        };
}
#pragma GCC diagnostic pop
