
#include "ParkingLot.h"
#include "Vehicle.h"
#ifndef BUS_H
#define BUS_H

class Bus : public Vehicle
{
    private:
        int row, col;
    public:
        Bus();
        ~Bus();
        void park(ParkingLot* pl);
};

#endif