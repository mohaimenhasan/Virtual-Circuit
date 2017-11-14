/* 
 * File:   NodeList.h
 * Author: khanmo87
 *
 * Created on November 3, 2016, 10:00 AM
 */

#ifndef NODELIST_H
#define	NODELIST_H
#include "Node.h"  
#include <string>
#include <iostream>
#define MIN_ITERATION_CHANGE 0.0001
class NodeList { 
    private:  
        Node* head; //head pointer to the first node
    public: 
        //Constructor
        NodeList();
        
        //Destructor
        ~NodeList(); 
        
        //Function description has been given on the source file
        //
        //
        //
        //
        
        Node* findNode(int nodeID);
        
        void insertNode(int nodeID);
        
        void addResistor(int nodeID, string name_,double resistance_,int endpoints_[2]);
        
        bool resistorExistsorNot(string resistorName);
        
        void changeResistance(string resistorName, double resistance);
        
        double getRes(string resName);
        
        void printAllNodes();
        
        Node* getHead();
        
        bool newNodeorNot(int nodeID);
        
        void printNode(int nodeID);
        
        void printResInfo(string name);
        
        void deleteEverything();
        
        void deleteRes(string name);
        
        void solveVolt();
        
        void deleteAllNodes();
        
        
        
};  


#endif	/* NODELIST_H */

