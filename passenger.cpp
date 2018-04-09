#include <cstring>
#include <iostream>
#include <fstream>
#include <cstring>
#include "passenger.h"
using namespace std;


Passenger::Passenger() 
{
} // Passenger()


Passenger::Passenger(short flightNu, short ro, char sea, const char nam[]) : 
  flightNum(flightNu), row(ro), seat(sea)
{
  strcpy(name, nam);
}  // Passenger()


void Passenger::copyPassengers()
{
  Passenger passenger;

  ifstream inf("passengers.dat", ios::binary);
  ofstream outf("passengers2.dat", ios::binary);

  while(inf.read( (char*) &passenger, sizeof(Passenger)))
    outf.write((char*) &passenger, sizeof(Passenger));

  outf.close();
  inf.close();
}  // copyPassengers()

bool Passenger::operator==(int n) const
{
  if(flightNum == n)
    return true;
  else //not the flight mathced
    return false;
} //operator==int(n)

bool Passenger::operator==(const char* n) const
{
  if(strcmp(name, n) == 0)
    return true; 
  else //not the name matched
    return false;
} //operator==char*n

Passenger& Passenger::operator!()
{
  flightNum = CANCELLED;
  return *this;
} //operator!

ostream& operator<<(ostream& os, const Passenger &passenger)
{
  os << passenger.name << endl;
  return os;
} //operator<<()


