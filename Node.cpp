#include "Node.h"
#include <iostream>
#include <iomanip>
using namespace std; 

//Initilizes the default constructor  
Node::Node(int nodeID)
{
    nodeNum = nodeID;
    ResistorList newResistorList;
    volt = 0;
    userDef = false;
    next = NULL; //initializes default next node to NULL by pointing it to NULL pointer 
}
//Default destructor
Node::~Node(){
    
}

//Function to check if resistor exists
bool Node::checkResistor(string res)
{
    Resistor* ptr1;
    ptr1 = newResistorList.getHead();
    if (ptr1 == NULL)
        return false;
    else
    {
        while(ptr1 != NULL)
        {
            if (ptr1->getName() == res)
                return true;
            ptr1 = ptr1->getNext();
        }
    }
    return false;
}

//Returns the next to the node
Node* Node::getNext()
{
    return next;
}


//Sets the node ID
void Node::setNodeNum(int newNum)
{
    nodeNum = newNum;
}

//Returns the node ID
int Node::getNodeNum(){
    return nodeNum;
}

//Adds resistors to the resistor list
void Node::addResistortoList(string name_,double resistance_,int endpoints_[2])
{
    newResistorList.addResistors(name_, resistance_, endpoints_);
}

//sets the next node to the node provided
void Node::setNext(Node* ptr)
{
    next = ptr;
}

//Changes the resistance of the resistor
void Node::changeResistor(string name, double res)
{
    newResistorList.changeRes(name, res);
}


//Returns the resistance
double Node::getResistance(string res)
{
    return newResistorList.returnRes(res);
}

//Prints all the resistors
void Node::printallResistor()
{
    Resistor* ptr1;
    ptr1 = newResistorList.getHead();
    while (ptr1!=NULL)
    {
        cout<<"   "<<left << setw(20)<<ptr1->getName()<<"  "<< right << setw(8) << ptr1->getResistance()<<" Ohms "<<ptr1->getEndpoint1()<<" -> "<<ptr1->getEndpoint2()<<endl;
        ptr1 = ptr1->getNext();
    }
}


//Returns the total resistors in the node
int Node::totalResistorsinNode()
{
    Resistor* ptr1;
    ptr1 = newResistorList.getHead();
    int counter = 0;
    while(ptr1!=NULL)
    {
        counter = counter+1;
        ptr1=ptr1->getNext();
    }
    return counter;
}

//Prints the resistors

void Node::printResistor(string res)
{
    Resistor* ptr;
    ptr = newResistorList.getHead();
    while(ptr!=NULL)
    {
        if(ptr->getName()==res)
        {
            cout<<left<<setw(20)<<ptr->getName()<<"  "<< right << setw(8) << ptr->getResistance()<<" Ohms "<<ptr->getEndpoint1()<<" -> "<<ptr->getEndpoint2()<<endl;
            break;
        }
        ptr = ptr->getNext();
    }
}


//Deletes all the resistors
void Node::deleteAllResistors()
{
    newResistorList.deleteAllRes();
}


//Deletes one resistor
void Node::deleteRes(string name)
{
    newResistorList.deleteResistor(name);
}

//Sets the voltage
void Node::setVolt(double resistance_)
{
    //sets boolean variable to true
    userDef = true;
    volt = resistance_;
}

//Sets the voltage to zero
void Node::unSetVolt()
{
    userDef = false;
    volt = 0;
}

//returns the voltage
double Node::getVolt()
{
        return volt;
}

//Returns if the voltage has been set by the user or not
bool Node::userVoltDef()
{
    return userDef;
}


//Sets voltage by default to 0 but boolean variable doesn't change
void Node::setVoltByDefault(double res)
{
    volt = res;
}

//Return total inverse res
double Node::totalInverseRes()
{
    return newResistorList.totalInvResinList();
}


//returns the other node that the resistor is connected to
int Node::getNodeID(int resNUM, int nodeID)
{
    return newResistorList.otherNodeID(resNUM, nodeID);
}

//returns resistor value based on it's connecting number 
int Node::getResVal(int resNum)
{
    return newResistorList.resVal(resNum);
}