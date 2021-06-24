#include "IPlantCarrier.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
namespace plant_imager_mocks {
        class PlantCarrierMock : public plant_carrier::IPlantCarrier {
        public:
            MOCK_METHOD(int32_t, demo_function, (int32_t num1, int32_t num2), (override));
        };
}
#pragma GCC diagnostic pop
