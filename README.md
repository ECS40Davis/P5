# P5 

***This looks better when read in the edit menu***

We will need a citylist.cpp and a citylist.h

NEW CLASSES: CityList and CityNode
  CityNode contains City and CityNode*
  CityList will be a friend to the CityNode class (im not sure what it means to be a friend?)
                **just learned what friend is. If classA is friend of classB, A can access B's private stuff**
  Add a copy constructor to City class for CityNode constructor to work
    remember to initialize!
  CityList contains CityNode* named head, CityNode* named tail, and an int named count
  CityList constructor will create an empty list
  CityList destructor will remove all of the CityNodes in the list
  
  Add a  getCount() method
  
  Move Vector code to main.cpp
  Gloabl replace Vector to CityList in main.cpp (netbeans replace option)
  Change cities from object(class) to parameter in all functions and function calls in main.cpp
  Copy Vector code (NOT constructor, destructor, resize) to main.cpp
  Remove Vector:: from beginning of all functions
  Add CityList reference named cities as first parameter.
  Copy prototypes from vector.h to top of main.cpp
  Add CityList reference as the first parameter
  
  Remove calls using cities-> and add cities as first parameter to the function
  Global replace "count" with "cities.getCount()"       this will give compiling errors at first
  Rework cleanup() to utilize the -= operator of CityList
  Change code in readcities to incorporate CityList += operator by reading file into temp City
  
  Global replace "cityArray" with "cities" 
  
  Add overloaded operators to various classes
  Change calling codes after operators
  City class
    change isEqual to an overloaded == operator              change parameter from pointer to reference
    change compareAirport to an overloaded == operator       it now takes const char* as parameter
    readCity to typical overloaded extraction operator with an istream ref and City ref as parameters
    calcDistance to overloaded minus operator.              change parameter from pointer to reference
    
    
    
***I think the best way of going about this program is to just follow Sean's steps in how he wrote it***
***Like start with CityList and CityNode classes, then go to Vector/main, then Add overloaded operators, etc***
***This one hopefully won't take too long, but it's very prone to bugs so be careful! haha***
