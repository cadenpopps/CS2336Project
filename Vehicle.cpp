#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "ParkingLot.h"
using namespace std;

Vehicle :: Vehicle()
{
    
    // cout << "Vehicle";

}

void Vehicle :: park(ParkingLot* pl){

    cout << endl << "Attempting to insert a car..." << endl;
    vector <int> spotCoords = pl->emptySpot();
    if(spotCoords[0] != -1 && spotCoords[1] != -1 && spotCoords[2] != -1){
        level = spotCoords[0];
        row = spotCoords[1];
        spot = spotCoords[2];
        cout << "Inserting car into level " << level << ", row " << row << ", spot " << spot  << endl << endl;
        pl->insertVehicle(level, row, spot, this);
    }
    else{
        cout << "No available spots, aborting..." << endl;
    }
}

Vehicle :: ~Vehicle(){}