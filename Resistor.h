#ifndef RESISTOR_H
#define RESISTOR_H
#include <string>
#include <iostream>
using namespace std;

class Resistor
{
private:
   double resistance; // resistance (in Ohms)
   string name; // C++ string holding the label
   int endpointNodeIDs[2]; // IDs of nodes it attaches to
   int ID;
   Resistor* next; //next resistor
public:
   Resistor(string name_,double resistance_,int endpoints_[2]);
   // rIndex_ is the index of this resistor in the resistor array
   // endpoints_ holds the node indices to which this resistor connects
   Resistor(); // constuctor 
   ~Resistor(); //destructor
   int getEndpoint1();
   int getEndpoint2();
   string getName() const; // returns the name
   double getResistance() const; // returns the resistance
   void setResistance (double resistance_);
   Resistor* getNext();
   // you *may* create either of the below to print your resistor
   void print ();
   void setNext(Resistor* res);
};

#endif	/* RESISTOR_H */

