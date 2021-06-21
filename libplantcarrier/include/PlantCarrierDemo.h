#ifndef CABLEBOT_BUILD_AND_TEST_CABLEBOTLIBDEMO_H
#define CABLEBOT_BUILD_AND_TEST_CABLEBOTLIBDEMO_H

#include "IPlantCarrierDemo.h"

namespace plant_imager {

        class PlantCarrierDemo : public IPlantCarrierDemo {
                public:
                    PlantCarrierDemo() = default;
                        ~PlantCarrierDemo() override = default;
                        int32_t Demo_function(int32_t num1, int32_t num2) override;
        };

}
#endif
