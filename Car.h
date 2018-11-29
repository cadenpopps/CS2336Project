
#include "ParkingLot.h"
#include "Vehicle.h"
#ifndef CAR_H
#define CAR_H

class Car : public Vehicle
{
    private:
        int row, col;
    public:
        Car();
        ~Car();
        // void park(ParkingLot* pl);
};

#endif