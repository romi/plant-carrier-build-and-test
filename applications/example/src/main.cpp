
#include <iostream>
#include "PlantCarrierDemo.h"


// LCOV_EXCL_START

int main()
{
    plant_imager::PlantCarrierDemo demo;

    auto result = demo.Demo_function(1, 2);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// LCOV_EXCL_END
