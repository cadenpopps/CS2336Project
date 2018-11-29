#include <iostream>
#include <vector>
#include "ParkingLot.h"
#include "Vehicle.h"

using namespace std;

ParkingLot :: ParkingLot()
{
    levels = 5;
    rows = 3;
    spots = 30;
    lot.resize(levels);
    for (int i = 0; i < levels; i++)
    {
        lot[i].resize(rows);
        for (int j = 0; j < rows; j++)
        {
            lot[i][j].resize(spots);
            for (int k = 0; k < spots; k++)
            {
                lot[i][j][k] = 'T';
            }
        }
    }
}

ParkingLot :: ParkingLot(int l, int r, int s)
{
    levels = l;
    rows = r;
    spots = s;
    int numLargeSpots = (rows * spots) * .2;
    int numSmallSpots = (rows * spots) * .2;

    lot.resize(levels);
    for (int i = 0; i < levels; i++)
    {
        lot[i].resize(rows);
        for (int j = 0; j < rows; j++)
        {
            lot[i][j].resize(spots);
            for (int k = 0; k < spots; k++)
            {
                int position = k + (j * spots);
                if (position < numLargeSpots)
                {
                    lot[i][j][k] = 'l';
                }
                else if (position >= (rows * spots) - numSmallSpots)
                {
                    lot[i][j][k] = 'm';
                }
                else
                {
                    lot[i][j][k] = 'c';
                }
            }
        }
    }
}

ParkingLot :: ParkingLot(int l, int r, int s, int large, int small)
{
    levels = l;
    rows = r;
    spots = s;
    int numLargeSpots = (rows * spots) * (large / 100);
    int numSmallSpots = (rows * spots) * (small / 100);

    lot.resize(levels);
    for (int i = 0; i < levels; i++)
    {
        lot[i].resize(rows);
        for (int j = 0; j < rows; j++)
        {
            lot[i][j].resize(spots);
            for (int k = 0; k < spots; k++)
            {
                int position = k * (j * spots);
                if (position < numLargeSpots)
                {
                    lot[i][j][k] = 'l';
                }
                else if (position > (rows * spots) - numSmallSpots)
                {
                    lot[i][j][k] = 'm';
                }
                else
                {
                    lot[i][j][k] = 'c';
                }
            }
        }
    }
}


ParkingLot :: ~ParkingLot(){}

vector <int> ParkingLot :: emptySpot(){
    vector <int> coordinates = {-1, -1, -1};

    for (int i = 0; i < levels; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < spots; k++)
            {
                char spotState = lot[i][j][k];
                if(spotState == 'l' || spotState == 'c'){
                    cout << i << " " << j << " " << k;
                    coordinates[0] = i;
                    coordinates[1] = j;
                    coordinates[2] = k;
                    return coordinates;
                }
            }
        }
    }

    return coordinates;
}

vector <int> ParkingLot :: emptySpot(int vehicleType){
    vector <int> coordinates = {-1, -1, -1};
    return coordinates;
}

void ParkingLot :: insertVehicle(int level, int row, int spot, Vehicle* vehicle){
    vehicles.push_back(vehicle);
    lot[level][row][spot] = 'C';
    this->toString();
}

bool ParkingLot :: isFull(){
    for (int i = 0; i < levels; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < spots; k++)
            {
                char spotState = lot[i][j][k];
                if(spotState == 'l' || spotState == 'c' || spotState == 'm'){
                    return false;
                }
            }
        }
    }
    return true;
}

void ParkingLot :: toString()
{
    for (int i = 0; i < levels; i++)
    {
        cout << "Level " << i + 1 << ": ";
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < spots; k++)
            {
                cout << lot[i][j][k];
            }
            cout << " ";
        }
        cout << endl;
    }
}