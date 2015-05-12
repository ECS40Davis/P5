#ifndef CITYLIST_H
  #define CITYLIST_H

#include "city.h"

class CityNode;

class CityList
{
  CityNode *head, *tail;
  static int count;
public:
  CityList(); // Default constructor
  ~CityList(); // Default destructor
  static int getCount();  
  CityList& operator+= (const City &rhs);
  CityList& operator-= (const City &rhs);
  CityList& operator[] (int index);
}; // CityList


class CityNode
{
  City city;
  CityNode *next;
public:
  friend class CityList; // Allows CityList to access node data.
  
  CityNode(); // Default constructor
  CityNode(const City &c, CityNode *n); // Standard constructor
}; // CityNode

#endif // CITYLIST_H
