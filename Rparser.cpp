
/* 
 * File:   Parser.cpp
 * Author: khanmo87
 *
 * Created on September 29, 2016, 9:08 AM
 */


#include "Rparser.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip> 
#include "ResistorList.h"
#include "NodeList.h"
using namespace std;
//Function to check if user inputs are valid or not 
//Function to check for 
void command(string line);

int parser () 
{
    NodeList myNodes; //list of all nodes
    string command; //Variable to take user inputs
    string nameholder; //Variable to store user input for any resistor name
    string all; //Variable to check later on if it's == all or not
    string line;
    double voltage;
    double checkValue; //Double to take resistance value
    int checkNode1, checkNode2; //Variables for the node
    int checkNodeID; //Variable to check nodeID
    cout<<fixed<<setprecision(2); //set precision to 2 decimal places
    cout<<"> ";
    // Get a line from standard input
    getline (cin, line);
    //Loop runs tills line == end of file 

    while ( !cin.eof () ) 
    {
        //Running the function to take in commands and the string entered by the user
        stringstream lineStream (line); //Creates a new string stream to put the user input string in 
        stringstream check (line); //Creates another string stream that can be used for checking for "all" for nodeIDs 
        lineStream >> command; //Puts the first part of the user enter string into the string variable
        
    if (command == "insertR")
    {
        //if it's the end of the file then its immediately an error for not having too many arguments
            //Puts anything after the command into the string to hold names.
            
            lineStream >> nameholder;
            
           //Checks if the name is all and then gives out the error 
            if (nameholder == "all")
            {
                cout<<"Error: resistor  name  cannot  be  the keyword \"all\""<<endl; 
            }

            else
            {
                //Checks for the value of resistance by putting the value of resistor to a float variable
                lineStream >> checkValue;
                //Checks for nodes by integers
                lineStream >> checkNode1;
                lineStream >> checkNode2; 
                if(myNodes.resistorExistsorNot(nameholder) == false)
                {
                    if (checkNode1 == checkNode2)
                        cout << "Error: both terminals of resistor connect to node "<< checkNode1 <<endl;
                    else
                    {
                        int node[2]; //creates an array to store the nodes
                        node[0] = checkNode1; 
                        node[1] = checkNode2;
                        if (myNodes.newNodeorNot(checkNode1) == false)
                            myNodes.insertNode(checkNode1);
                        if (myNodes.newNodeorNot(checkNode2) == false)
                            myNodes.insertNode(checkNode2);
                        myNodes.addResistor(checkNode1, nameholder, checkValue, node);
                        myNodes.addResistor(checkNode2, nameholder, checkValue, node);
                        cout<<"Inserted: resistor "<< nameholder << " "<<checkValue<<" Ohms "<<checkNode1<<" -> "<<checkNode2<<endl; 
                    }
                }
                else
                   cout<<"Error: resistor "<<nameholder<<" already exists"<<endl;
                              
               
            }
        
    }    
    else if (command == "setV")
    {
        lineStream>>checkNode1;
        lineStream>>voltage;
        if(myNodes.newNodeorNot(checkNode1) == false)
            cout<<"Error: node "<<checkNode1<<" not found"<<endl;
        else
        {
            myNodes.findNode(checkNode1)->setVolt(voltage);
            cout<<"Set: node "<<checkNode1<<" to "<<voltage<<" Volts"<<endl;
        }
    }
    else if (command == "unsetV")
    {
        lineStream>>checkNode1;
        if(myNodes.newNodeorNot(checkNode1) == false)
            cout<<"Error: node "<<checkNode1<<" not found"<<endl;
        else
        {
            myNodes.findNode(checkNode1) ->unSetVolt();
            cout<<"Unset: the solver will determine the voltage of node "<<checkNode1<<endl;
        }
    }
    else if (command == "solve")
    {
        myNodes.solveVolt();
    }
    //Modify resistance
    else if (command == "modifyR")
    {
        //Checks for eof at the beginning 
            //name for modification
            lineStream>>nameholder;
            lineStream>>checkValue;
            double previous_resistance = myNodes.getRes(nameholder);
            if(myNodes.resistorExistsorNot(nameholder))
            {
                myNodes.changeResistance(nameholder, checkValue);
                cout<<"Modified: resistor "<<nameholder<<" from "<<previous_resistance<<" Ohms to "<<checkValue<<" Ohms"<<endl;
            }
            else
                cout<<"Error: resistor "<<nameholder<<" not found"<<endl;
            
    }    
    //Print resistor    
    else if (command == "printR")
    {
        lineStream>>nameholder;
        if(myNodes.resistorExistsorNot(nameholder) == false)
            cout<<"Error: resistor "<<nameholder<<" not found"<<endl;
        else
        {
            cout<<"Print:"<<endl;
            myNodes.printResInfo(nameholder);
        }
            
              
    }    
    else if (command == "printNode") 
    {
            lineStream >> checkNodeID;
            //If not an int then it checks by putting the string line 
            if (lineStream.fail()) 
            {
                //Checks by putting input string into a new string stream 
                check >> command;  
                check >> all;
                if (all == "all")
                { 
                    cout<<"Print:"<<endl;
                    myNodes.printAllNodes();
                }
            }
            //Checks for node value
            
            //EOF
            else if (lineStream.eof())
            {
                cout<<"Print:"<<endl;
                if (myNodes.newNodeorNot(checkNodeID))
                {
                    myNodes.printNode(checkNodeID);
                }
            }                        
        
    }
    
    //Delete R
    else if (command == "deleteR")
    {
        lineStream >> nameholder;
        //Deletes the arrays
        //Sets the pointers to NULL
        //Reassign the arrays
        if (nameholder == "all")
        {
            myNodes.deleteEverything();
            myNodes.deleteAllNodes();
            cout<<"Deleted: all resistors"<<endl;
        }
        else
        {
            if(myNodes.resistorExistsorNot(nameholder) == false)
                cout<<"Error: resistor "<<nameholder<<" not found"<<endl;        
            else
            {
                myNodes.deleteRes(nameholder);
                cout<<"Deleted: resistor "<<nameholder<<endl;
                
            }
        }
            
    }
    else 
    {
        cout<<"Error: invalid command"<<endl;
    }
        //Clears the input stream 
        cin.clear();
        cout<<"> ";
        
        //Asks for a new input by the end of executing command function
        getline (cin, line);
        
    }  // End input loop until EOF.

    //Checks for anything leftover
    //Deletes everything
    myNodes.deleteEverything();
    myNodes.deleteAllNodes();
            
    return 0;
}


