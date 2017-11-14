#include "NodeList.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Default constructor
NodeList::NodeList()
{
    head = NULL;
}

//Default destructor
NodeList::~NodeList()
{
   
}

//Function to add a resistor to a node
void NodeList::addResistor(int nodeID, string name_,double resistance_,int endpoints_[2])
{
    Node* ptr; //pointer to the head of the list of nodes
    ptr = head; 
    //checks if head is empty
    //Adds resistors only if it is not
    while (ptr!=NULL)
    {
        //Matches the nodeID to add the resistor to the node
        if(ptr->getNodeNum() == nodeID)
        {
            //Adds resistor and breaks out of the loop
            ptr->addResistortoList(name_, resistance_, endpoints_);
            break;
        }
        //keeps on looping throgh the list till the end
        ptr = ptr->getNext();
    }
}

//returns a pointer to the node with matching nodeID
Node* NodeList::findNode(int nodeID)
{
    //Dummypointer to go through the entire node list
    Node* dummyPointer; 
    dummyPointer = head;
    //checks till the end
    while(dummyPointer != NULL)
    {
        //breaks out if node ID is found
        if (dummyPointer->getNodeNum() == nodeID)
        {
            break; 
        }
        dummyPointer = dummyPointer->getNext();
    }
    return dummyPointer;
}

//Function to insert a Node by sorting it based on nodeID
void NodeList::insertNode(int nodeID)
{

    if (head == NULL) //creates a new node if there aren't any 
    {
        head = new Node(nodeID);
        return;
    }
    else
    {        
        Node* newNode; //Creates a new Node pointer to point to the newly created node
        //Check if the new node is before head
        if(head->getNodeNum() > nodeID)
        {   
            newNode = new Node(nodeID); //creates a new node with node ID
            newNode->setNext(head);//Point new node to head and make new node head
            head = newNode; //sets the head pointer to the newly created Node
            return;
        }
        
        //Two pointer to head and head's next
        Node* prev = head; //pointer to the head
        Node* next; //pointer to head's next
        //If head has two elements and need to be added at the end
        if(head->getNodeNum() < nodeID and head->getNext() == NULL) 
        {
            next = new Node(nodeID);
            prev->setNext(next); //sets the lists end to the new node
            return;
        }
        next = head->getNext();
        while(next!=NULL)
        {
            //checks where the new node should be sorted
            if(nodeID < next->getNodeNum())
            {
                newNode = new Node(nodeID);    
                newNode->setNext(next);
                prev->setNext(newNode); 

                break;//Should get us out of this loop
            }

            //Update next and prev everytime the loop is run
            prev = next;
            next = next->getNext();

        }
        //If need to be added at the end
        if(prev->getNext() == NULL)
        {
            Node* addEnd = new Node(nodeID);
            prev->setNext(addEnd);
            return;
        }
        
    }
}

//Prints all the nodes with the resistors
void NodeList::printAllNodes()
{
    //ptr1 points to the head of the list 
    Node* ptr1;
    ptr1 = head;
    //head == NULL - print nothing 
    if (ptr1 == NULL)
    {
        return;
    }
    //If not NULL then goes through each node and prints the resistors
    while(ptr1!=NULL)
    {
        //all resistors are printed till the end
        if(ptr1->totalResistorsinNode()>0)
        {
            cout<<"Connections at node "<<ptr1->getNodeNum()<<": "<<ptr1->totalResistorsinNode()<<" resistor(s)"<<endl;
            ptr1->printallResistor();
        }
        
        ptr1 = ptr1 ->getNext();
    }
}

//Checks if the resistor exists or not
bool NodeList::resistorExistsorNot(string resistorName)
{
    //CheckPtr to the head
    Node* checkPtr;
    checkPtr = head;
    //If head == null then returns false
    if (checkPtr == NULL)
        return false;
    else 
    {
        //If not null then keeps on traversing till the end
        while(checkPtr != NULL)
        {
            //If true then breaks out and returns true
            if(checkPtr->checkResistor(resistorName))
                return true;
            checkPtr = checkPtr->getNext();
        }
    }
    //returns false if conditions doesn't meet
    return false;
}        


//returns the head of node list
Node* NodeList::getHead()
{
    return head;
}



//Searches through all the nodes and changes the resistance
void NodeList::changeResistance(string resistorName, double resistance)
{
    Node* searchPtr;
    
    searchPtr = head;
    
    while(searchPtr != NULL)
    {
        if(searchPtr->checkResistor(resistorName))
        {
            searchPtr->changeResistor(resistorName, resistance);
        }
        searchPtr = searchPtr->getNext();
    }
    
}


//returns res by going though the nodes 
double NodeList::getRes(string resName)
{
    Node* nodePtr;
    
    nodePtr = head;
    
    while(nodePtr!= NULL)
    {
        if(nodePtr->checkResistor(resName))
        {

            return nodePtr->getResistance(resName);
            
        }
        nodePtr = nodePtr->getNext();
    }
}

//checks if the Node exists or not
bool NodeList::newNodeorNot(int nodeID)
{
    //ptr1 to the head
    Node* ptr1;
    ptr1 = head;
    //returns false if nothing exists
    if (ptr1 == NULL)
        return false;
    
    //if not empty then checks again the nodeID
    while (ptr1 != NULL)
    {
        if(ptr1->getNodeNum() == nodeID)
            return true;
        ptr1 = ptr1->getNext();
    }
    return false; //Not found then returns false
}


//Prints the entire node with the node ID and resistors
void NodeList::printNode(int nodeID)
{
    Node* ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->getNodeNum() == nodeID)
        {
            if(ptr->totalResistorsinNode()>0)
            {
            cout<<"Connections at node "<<ptr->getNodeNum()<<": "<<ptr->totalResistorsinNode()<<" resistor(s)"<<endl;
            ptr->printallResistor();
            break;
            }
        }
        ptr = ptr->getNext();
    }
}

//Prints one single resistor information
void NodeList::printResInfo(string name)
{
    Node* ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->checkResistor(name))
        {
            ptr->printResistor(name);
            break;
        }
        ptr=ptr->getNext();
    }
}

//Deletes all the resistor
void NodeList::deleteEverything()
{
    Node* tempPtr;
    tempPtr = head;
    while(tempPtr!=NULL)
    {        
        tempPtr->deleteAllResistors();
        tempPtr = tempPtr->getNext();
    }
}


//deletes a single resistor
void NodeList::deleteRes(string name)
{
    Node* ptr = head;
    if (ptr!=NULL)
    {
        while(ptr!=NULL)
        {
            if(ptr->checkResistor(name))
                ptr->deleteRes(name);
            ptr = ptr->getNext();  
        }
    }
}


//Function to solve voltage
void NodeList::solveVolt()
{
    double change = 0;
    double initialVoltage;
    double finalVoltage;
    double previousMinimumChange = 0;
    double minimumChange;
    bool checkforVoltage = false;
    bool changeLessthanMINIteration = false;
    Node* checkforVolt = head;
    
    //Checks if any one of the node voltage have been defined
    while(checkforVolt!=NULL)
    {
        
        if(checkforVolt->userVoltDef())
        {
            checkforVoltage = true;
            break;
        }
        checkforVolt = checkforVolt->getNext();
    }
    //Error statement
    if(checkforVolt == false)
    {
        cout<<"Error: no nodes have their voltage set"<<endl;
    }
    else
    {
        //Sets the pointer to the head
        Node* settingPtr = head;
        //Sets any undefined voltage to 0
        while(settingPtr!=NULL)
        {
            if(settingPtr->userVoltDef()==false)
            {
                settingPtr->setVoltByDefault(0);
            }
            settingPtr=settingPtr->getNext();
        }
        //Keeps on running till the end
        //checks if it satisfies the iteration condition
        while(changeLessthanMINIteration == false)
        {
            //sets the condition to true
            changeLessthanMINIteration = true;
            //ptr tracks the iteration
            //Runs till it is equal to NULL and if main condition satisfied then goes through the loop again
            Node*ptr1=head;
            while(ptr1!=NULL)
            {
                //Changes the value of the functions that haven't been defined by the user
            if(ptr1->userVoltDef() == false)
            {
                //Variable to get the voltage 
                initialVoltage = ptr1->getVolt();
                //Ptr2 = Pointer to go through the nodes
                Node*ptr2=ptr1;
                //variable to find what other node is the node connected to using the resistor
                int otherNode; 
                //Variable to get the value of the resistors connected to the node 
                double resistance;
                double current = 0; //Current coming into the node
                resistance = 1/(ptr2->totalInverseRes()); //Inverse of the inverse sum of all resistors
                int totalresInNode = ptr2->totalResistorsinNode(); //counts the total resistors 
                for(int i = 0; i<totalresInNode;i++)
                {
                    otherNode=ptr2->getNodeID((i+1), ptr2->getNodeNum());
                    Node*findptr;
                    double voltage;
                    double tempRes;
                    tempRes = ptr2->getResVal(i+1);
                    findptr=head;
                    while(findptr!=NULL)
                    {
                        if(findptr->getNodeNum()==otherNode)
                        {
                            voltage = findptr->getVolt();
                            break;
                        }
                        findptr=findptr->getNext();
                    }
                    current = current + voltage/tempRes; 
                }
                double finalVoltage = current * resistance;
                ptr1->setVoltByDefault(finalVoltage);
                minimumChange = abs(finalVoltage - initialVoltage); //finds the min voltage change
                if(minimumChange>MIN_ITERATION_CHANGE)
                    changeLessthanMINIteration = false; //sets it equal to false if condition not met
            }
            ptr1=ptr1->getNext();
            }

        }
        Node* printPtr = head;
        cout<<"Solve:"<<endl;
        while(printPtr!=NULL)
        {
            cout<<"  Node "<<printPtr->getNodeNum()<<": "<<printPtr->getVolt()<<" V"<<endl;
            printPtr = printPtr->getNext();
        }
    }
    
    
}

//Deletes all nodes
void NodeList::deleteAllNodes()
{
    while(head!=NULL)
    {
        Node* tempPtr;
        tempPtr = head;
        tempPtr = tempPtr->getNext();
        delete head;
        head = tempPtr; 
    }
    
}


