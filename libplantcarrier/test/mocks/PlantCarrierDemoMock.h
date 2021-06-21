#include "IPlantCarrierDemo.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
namespace plant_imager_mocks {
        class PlantCarrierDemoMock : public plant_imager::IPlantCarrierDemo {
        public:
            MOCK_METHOD(int32_t, Demo_function, (int32_t num1, int32_t num2), (override));
        };
}
#pragma GCC diagnostic pop
