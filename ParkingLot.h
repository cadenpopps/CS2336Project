#include <vector>
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

class Vehicle;

class ParkingLot
{
    private:
        std::vector<std::vector<std::vector<char> > > lot;
        std::vector<Vehicle*> vehicles;
        int levels;
        int rows;
        int spots;
    public:
        ParkingLot();
        ParkingLot(int l, int r, int s);
        ParkingLot(int l, int r, int s, int large, int small);
        ~ParkingLot();
        std::vector <int> emptySpot();
        std::vector <int> emptySpot(int vehicleType);
        void insertVehicle(int level, int row, int spot, Vehicle* vehicle);
        bool isFull();
        void toString();
};

#endif