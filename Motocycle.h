
#include "ParkingLot.h"
#include "Vehicle.h"
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

class Motorcycle : public Vehicle
{
    private:
        int row, col;
    public:
        Motorcycle();
        ~Motorcycle();
        void park(ParkingLot* pl);
};

#endif