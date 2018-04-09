#ifndef PASSENGER_H
#define	PASSENGER_H

#include "plane.h"

class Passenger 
{
public:
  static const int NAME_LENGTH = 30;
  static const int CANCELLED = -1;
private:
  short flightNum;
  short row; 
  char seat;
  char name[NAME_LENGTH];
  friend istream& operator>>(istream &is, Plane &plane);
  friend ostream& operator<<(ostream& os, const Passenger &passenger);
public:
  Passenger();
  Passenger(short flightNu, short ro, char sea, const char nam[]);
  bool operator==(int n) const;
  bool operator==(const char* n) const;
  Passenger& operator!();
  static void copyPassengers(); 
}; // class passengers 

#endif	// PASSENGERS_H
