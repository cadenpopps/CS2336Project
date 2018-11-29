
#include <iostream>
#include "ParkingLot.h"
#include "Vehicle.h"
#include "Car.h"

using namespace std;

vector<int> getSizeParametersFromUser();
vector<int> getAllParametersFromUser();

int main()
{

    vector<int> parameters = getSizeParametersFromUser();
    // vector<int> parameters = getAllParametersFromUser();

    ParkingLot *p = new ParkingLot(parameters[0], parameters[1], parameters[2]);
    // ParkingLot *p = new ParkingLot(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4]);
    p->toString();

    

    while(!p->isFull()){
        cout << endl << "What would you like to park next? (b = bus, c = car, m = motorcylce): ";
        char type;
        while (!(cin >> type) || (type != 'b' && type != 'c' && type != 'm'))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input.  Try again: ";
        }
        cin.clear();
        cin.ignore(100, '\n');
        if(type == 'c'){
            Car *c = new Car();
            c->park(p);
        }
        else{
            cout << "Not ready" << endl;
        }
    }

    return 0;
}

vector<int> getSizeParametersFromUser()
{
    vector<int> parameters(3);
    cout << "Input the number of levels: ";
    while (!(cin >> parameters[0]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    // cout << endl;
    cout << "Input the number of rows: ";
    while (!(cin >> parameters[1]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    // cout << endl;
    cout << "Input the number of spots per row: ";
    while (!(cin >> parameters[2]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    return parameters;
}

vector<int> getAllParametersFromUser()
{
    cout << endl;
    vector<int> parameters(5);
    cout << "Input the number of levels: ";
    while (!(cin >> parameters[0]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    // cout << endl;
    cout << "Input the number of rows: ";
    while (!(cin >> parameters[1]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    // cout << endl;
    cout << "Input the number of spots per row: ";
    while (!(cin >> parameters[2]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    cout << "Input the percent of large spots: ";
    while (!(cin >> parameters[3]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    cout << "Input the percent of motorcycle spots: ";
    while (!(cin >> parameters[4]))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.  Try again: ";
    }
    return parameters;
}