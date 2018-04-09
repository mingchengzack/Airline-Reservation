#ifndef PLANE_H
#define	PLANE_H
#include <fstream>

using namespace std;

#include "linkedlist.h"

class Plane
{
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  int rows;
  int width;
  int reserved;
  int flightNumber;
  LinkedList* passengers;
  int getRow() const;
  void showGrid() const;
  friend ostream& operator<<(ostream &os, const Plane &plane);
  friend istream& operator>>(istream &is, Plane &plane);
public:
  Plane(int fn);
  ~Plane();
  void addFlight();
  Plane& operator++();
  Plane& operator--(int);
  const Plane& operator!();
  int findPassenger(const char name[]) const;
  void writePlane(ofstream &outf) const;
}; // class Plane

#endif	// PLANE_H


