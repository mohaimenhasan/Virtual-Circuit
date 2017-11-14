#include "ResistorList.h"
#include "Node.h"
#include <string>
#include <iostream>


//Constructor
ResistorList::ResistorList()
{
    head = NULL;
    
}

//Returns the head to the list of resistors
Resistor* ResistorList::getHead()
{
    return head;
}

//Sets up the head to the list=
void ResistorList::setupHead(Resistor* ptr)
{
    head = ptr;
}

//Destructor
ResistorList::~ResistorList(){
    
}

//Adds the resistor to the list
void ResistorList::addResistors(string name_,double resistance_,int endpoints_[2])
{
    Resistor* ptr1;
    ptr1 = head;
    if (ptr1 == NULL)
    {
        ptr1 = new Resistor(name_, resistance_, endpoints_);
        head = ptr1;
    }
    else
    {
        while (ptr1->getNext() != NULL)
        {
            ptr1 = ptr1->getNext();
        }
        Resistor* ptr2 = new Resistor(name_, resistance_, endpoints_);
        ptr1->setNext(ptr2);
    }
}

//Changes resistance
void ResistorList::changeRes(string name, double res)

{
    Resistor* ptr;
    
    ptr = head;
    while(ptr->getNext()!=NULL)
    {
        if(ptr->getName() == name)
        {
            break;
        }
        ptr = ptr->getNext();
    }
    ptr->setResistance(res);
}


//Returns resistance based on name of resistors
double ResistorList::returnRes(string name)
{
    Resistor* ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->getName()==name)
            return ptr->getResistance();
        ptr = ptr->getNext();
    }
}


//deletes all the resistors
void ResistorList::deleteAllRes()
{
    while(head!=NULL)
    {
        Resistor* tempPtr;
        tempPtr = head;
        tempPtr = tempPtr->getNext();
        delete head;
        head = tempPtr; 
    }
}


//Deletes a single resistor
void ResistorList::deleteResistor(string name)
{
    Resistor* temp;
    temp = head;
    if(temp!=NULL)
    {
        //checks if resistor is at the beginning 
        if(temp->getNext()==NULL and temp->getName() == name)
        {
            delete temp;
            temp = NULL;
            head = temp;
        }
        //Traverse till the end
        while(temp->getNext()!=NULL)
        {
            Resistor* checkPtr;
            checkPtr = temp;
            checkPtr = checkPtr->getNext();
            if(temp->getName() == name)
            {
                delete temp;
                temp = NULL;
                head = checkPtr;
                break;
            }
            if(checkPtr != NULL and checkPtr->getName() == name)
            {
                Resistor* switchPtr;
                switchPtr = temp;
                temp = temp->getNext();
                switchPtr->setNext(temp->getNext());
                delete temp;
                temp = switchPtr;
                break;
            }            
            temp = temp->getNext();
        }
    }
    else
        return;
}


//Returns sum of inverse of each resistors
double ResistorList::totalInvResinList()
{
    double total = 0;
    Resistor* ptr= head;
    while(ptr!=NULL)
    {
        total = total + (1/(ptr->getResistance()));
        ptr=ptr->getNext();
    }
    return total;
}

//Returns the other node that the resistor is connected to

int ResistorList::otherNodeID(int resNum, int nodeID)
{
    Resistor* ptr = head;
    for(int i = 0;i<resNum-1;i++)
    {
        ptr=ptr->getNext();
    }
    if(ptr->getEndpoint1()==nodeID)
        return ptr->getEndpoint2();
    else
        return ptr->getEndpoint1();
}


//returns the resistance value based on the way it's connected 
double ResistorList::resVal(int resNum)
{
    Resistor* ptr =head;
    for(int i = 0;i< resNum-1;i++)
    {
        ptr = ptr->getNext();
    }
    return ptr->getResistance();
}