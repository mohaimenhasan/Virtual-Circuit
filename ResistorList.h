/* 
 * File:   ResistorList.h
 * Author: khanmo87
 *
 * Created on November 3, 2016, 9:48 AM
 */

#ifndef RESISTORLIST_H
#define	RESISTORLIST_H
#include "Resistor.h"
#include <string>
#include <iostream>

using namespace std;

class ResistorList { 
private:
    //pointer to the beginning of the list
        Resistor* head; 
    public: 
        
        //Function description has been given on the source file
        //
        //
        //
        ResistorList(); 
        ~ResistorList(); 
        Resistor* getHead();
        void setupHead(Resistor* ptr);
        void setNext(ResistorList* n); 
        void print() const; 
        void addResistors(string name_,double resistance_,int endpoints_[2]);
        void changeRes(string name, double res);
        double returnRes(string name);
        void deleteAllRes();
        void deleteResistor(string name);
        double totalInvResinList();
        int otherNodeID(int resNum, int nodeID);
        double resVal(int resNum);
}; 


#endif	/* RESISTORLIST_H */

