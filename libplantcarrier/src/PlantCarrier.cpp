#include "PlantCarrier.h"

namespace plant_carrier {
    PlantCarrier::PlantCarrier(IGripper& gripper)
    : gripper_(gripper)
    {
    }

    int32_t PlantCarrier::demo_function(int32_t num1, int32_t num2) {
            return num1 + num2;
    }
}
