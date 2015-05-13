#include "citylist.h"
#include "city.h"

// ----------------------------
// Static Variables and Methods
// ----------------------------
int CityList::count = 0;
int CityList::getCount()
{
  return count;
} // getCount()


// ----------------------------
// CityList Methods
// ----------------------------
CityList::CityList():head(NULL), tail(NULL) 
{
  count--;
} // default constructor



CityList::~CityList()
{
  CityNode *ptr;
  
  for (ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  } // move through Linked List
  
} // default destructor: removes all the CityNodes in the list


CityList& CityList::operator+= (const City &rhs)
{
  CityNode *ptr, *prev = NULL;
  for (ptr = head; ptr; ptr = ptr->next)
    prev = ptr;
  if (!head) // If no elements in list.
  {
    head = tail =  new CityNode(rhs, NULL); // head and tail = first element
  } // if no elements in the list
  
  else // if there are at least 2 elements in the list
  {
      prev->next = new CityNode(rhs, NULL);
      tail = prev->next;
  } // if there are at least 1 elements in the list

  count++;
  return *this;
} // operator+= (insert)

CityList& CityList::operator-= (const City &rhs)
{
    CityNode *ptr, *prev = NULL;
    for (ptr = head; ptr && !(ptr->city.isEqual(&rhs)); ptr = ptr->next)
    {
        prev = ptr;
    } // find city mentioned
    
    if (ptr) // if we found the city
    {
        if (!prev) // if the first node
        {
            head = ptr->next;
            if (!head) // if list was only 1 long 
                tail = NULL;
        } // if first node
        
        else // after first node
        {
            prev->next = ptr->next;
            if (!prev->next) // if the last node is going to be deleted
                tail = prev;
        } // after the first node
        
        count--;
        delete ptr;
    } // if city was found
    
    return *this;
} // operator -= (remove)


City& CityList::operator[] (int index)
{
  CityNode *ptr = head;
  for (int i = 0; i < index; i++)
      ptr = ptr->next;
  return ptr->city;
} // operator []

City& CityList::operator[] (int index) const
{
  CityNode *ptr = head;
  for (int i = 0; i < index; i++)
      ptr = ptr->next;
  return ptr->city;
} // operator []


// ----------------------------
// CityNode Methods
// ----------------------------
CityNode::CityNode():next(NULL) {} // default constructor

CityNode::CityNode(const City &c, CityNode *n)
{
    city = c;
    next = n;
} // Standard constructor
