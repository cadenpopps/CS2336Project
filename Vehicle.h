#ifndef VEHICLE_H
#define VEHICLE_H

class ParkingLot;

class Vehicle
{
    private:
        int level, row, spot;
    public:
        Vehicle();
        ~Vehicle();
        virtual void park(ParkingLot* pl);
};

#endif