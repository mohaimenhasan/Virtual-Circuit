
#include "Resistor.h"
#include <iostream>
#include <iomanip>
using namespace std;
    Resistor::Resistor(string name_,double resistance_,int endpoints_[2])
    {
        name = name_;
        resistance = resistance_;
        endpointNodeIDs[0] = endpoints_[0];
        endpointNodeIDs[1] = endpoints_[1];
        next = NULL;
    }
    
    Resistor* Resistor::getNext()
    {
        return next;
    }
    //Default constructor
    Resistor::Resistor(){ 
        
    }
    //Default destructor
    Resistor::~Resistor(){
        
    }
    //sets the next resistor
    void Resistor::setNext(Resistor* res)
    {
        next = res;
    }

   string Resistor::getName() const
   {
       return name;
   } // returns the name
   double Resistor::getResistance() const
   {
       return resistance;
   } // returns the resistance
   void Resistor::setResistance (double resistance_)
   {
       resistance = resistance_;
   }
   // prints the resistors
   void Resistor::print ()
   {
       cout<<left << setw(20)<<name<<"  "<< right << setw(8) << resistance<<" Ohms "<<endpointNodeIDs[0]<<" -> "<<endpointNodeIDs[1]<<endl;
   }
   
   //returns one of the endpoints that it is connected to
   int Resistor::getEndpoint1()
   {
       return endpointNodeIDs[0]; 
   }
   
   //returns the other endpoint that it is conneceted to
   int Resistor::getEndpoint2()
   {
       return endpointNodeIDs[1];
   }
   
