/* 
 * File:   Node.h
 * Author: JC and VB
 * Author: TSA
 *
 * Updated on August 24, 2016, 01:40 PM
 * Created on October 6, 2013, 12:58 PM
 */

#ifndef NODE_H
#include "ResistorList.h"


class Node
{
private:
    
   int nodeNum; //NodeID
   ResistorList newResistorList; //creates a resistorlist class everytime Node is invoked
   double volt;
   bool userDef;
   Node* next; //points to the next node

public:
    
    
     
    Node(int nodeID); //Constructor
   
   //Destructor
   ~Node();
   
   //Function description has been given on the source file
   //
   //
   //
   
   bool checkResistor(string res);
   double getResistance(string res);
   int getNodeNum();
   void setNodeNum(int newNum);
   void addResistortoList(string name_,double resistance_,int endpoints_[2]);
   void setNext(Node* ptr);
   Node* getNext();
   void printallResistor();
   void changeResistor(string name, double res);
   int totalResistorsinNode();
   void printResistor(string res);
   void deleteAllResistors();
   void deleteRes(string name);
   void setVolt(double resistance_);
   void unSetVolt();
   double getVolt();
   bool userVoltDef();
   void setVoltByDefault(double res);
   double totalInverseRes();
   int getNodeID(int resNUM, int nodeID);
   int getResVal(int resNum);
};

#endif	/* NODE_H */

