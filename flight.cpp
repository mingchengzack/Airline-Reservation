#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"

using namespace std;

const Flight& Flight::operator++(int)
{
  ++(*plane);
  return *this;
}  // operator++()


Flight::~Flight()
{
  ofstream outf("flights2.csv", ios::app);
  outf << flightNum << ',' << origin << ',' << destination << ',';
  plane->writePlane(outf);
  outf.close();
  delete plane;
}  // freeFlight()

void Flight::addFlight()
{
  cout << "\nFlight number to add: ";
  cin >> flightNum;
  cin.ignore(TEN, '\n');
  cout << "Origin: ";
  cin.getline(origin, MAX_CITY_LENGTH);
  cout << "Destination: ";
  cin.getline(destination, MAX_CITY_LENGTH);
  plane = new Plane(flightNum);
  plane->addFlight();
}  // addFlight()

int Flight::getFlightNumber() const
{
  return flightNum;
}  // getFlightNumber()


ostream& operator<<(ostream& os, const Flight& flight)
{
  os << left << setw(Flight::FLIGHT_NUM_SPACE) << flight.flightNum << ' ' 
     << setw(Flight::MAX_CITY_LENGTH) << flight.origin << ' '  
     << flight.destination << endl;

  return os;
}  // operator<<()


istream& operator>>(istream &is, Flight& flight)
{ 
  is >> flight.flightNum;
  is.ignore(Flight::TEN, ',');
  is.getline(flight.origin, Flight::MAX_CITY_LENGTH, ',');
  is.getline(flight.destination, Flight::MAX_CITY_LENGTH, ',');
  flight.plane = new Plane(flight.flightNum);
  is >> *(flight.plane);
  return is;
}  // opeartor>>()


const Flight& Flight::operator!() 
{
  !(*plane);
  return *this;
}  // operator!();


const Flight& Flight::operator--()
{
  (*plane)--;
  return *this;

}  // operator--();

int Flight::findPassenger(const char name[]) const
{
  if(plane->findPassenger(name))
    return 1;
  else // not found
    return 0;
} //findPassenger()
