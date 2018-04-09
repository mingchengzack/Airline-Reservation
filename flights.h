#ifndef FLIGHTS_H
#define	FLIGHTS_H

#include "flight.h"

class Flights 
{
  static const int NAME_LENGTH = 30;
  static const int INITIAL_SIZE = 2;
  static const int RESIZE_MULTIPLIER = 2;
  static const int TEN = 10;
  Flight **flights;
  int size;
  int capacity;
  friend istream& operator>>(istream& is, Flights& flights);
public:
  Flights();
  ~Flights();
  void addPassenger() const;
  Flights& operator++();
  Flights& operator+=(Flight *flight);
  int getSize() const;
  Flights& operator--(int);
  void removePassenger() const;
  void findPassenger() const;
}; // class flights 

#endif	// FLIGHTS_H

