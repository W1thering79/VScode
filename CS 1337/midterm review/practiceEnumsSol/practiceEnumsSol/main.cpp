#include <iostream>
#include <string>
using namespace std;

int main() {

  enum VEHICLE_TYPE { CAR, TRUCK };

  struct Vehicle {
    string       brand;
    unsigned     year;
    VEHICLE_TYPE type;
  };

  Vehicle myVehicle;

  myVehicle = { "Ford", 2025, TRUCK };
  cout << myVehicle.type << " " << myVehicle.year << " " << myVehicle.brand << endl;

  return 0;
}

