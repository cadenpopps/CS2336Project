#include <iostream>
#include "Motorcycle.h"
#include "Vehicle.h"
#include "ParkingLot.h"
using namespace std;

Motorcycle :: Motorcycle() : Vehicle()
{
  
}

Motorcycle :: ~Motorcycle(){}

void Motorcycle::park(ParkingLot* pl){

    cout << endl << "Attempting to insert a motorcycle..." << endl;
    vector <int> spotCoords = pl->emptySpot(1);
    if(spotCoords[0] != -1 && spotCoords[1] != -1 && spotCoords[2] != -1){
        level = spotCoords[0];
        row = spotCoords[1];
        spot = spotCoords[2];
        cout << "Inserting motorcycle into level " << level << ", row " << row << ", spot " << spot  << endl << endl;
        pl->insertVehicle(level, row, spot, this);
    }
    else{
        cout << "No available spots, aborting..." << endl;
    }

}