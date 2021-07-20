//
// Created by nicolasbranas on 15/07/2021.
//

#ifndef PLANT_CARRIER_BUILD_AND_TEST_WORKSESSION_H
#define PLANT_CARRIER_BUILD_AND_TEST_WORKSESSION_H

#include "IScanner.h"
#include "IPlantCarrier.h"


class WorkSession {

protected:
    IScanner& scanner_;
    plant_carrier::IPlantCarrier& plant_carrier_;
    int plant_number_;
public:
    WorkSession(IScanner& scanner, plant_carrier::IPlantCarrier& pc, int plant) : scanner_(scanner),plant_carrier_(pc),plant_number_(plant){}
    ~WorkSession() = default;
    const plant_carrier::IPlantCarrier& get_pc() const{return plant_carrier_;}
    plant_carrier::IPlantCarrier& get_pc() {return plant_carrier_;}
    int get_plant_number() const {return plant_number_;}
};


#endif //PLANT_CARRIER_BUILD_AND_TEST_WORKSESSION_H
