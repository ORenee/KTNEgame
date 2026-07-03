/**
 * @file Knob.cpp
 * @author Renee Olds
 */

#include "Knob.h"
#include <iostream>
using namespace std;

string Knob::getInput(){
    string in;
    getline(cin, in);
    if(knobInput.find(in) == knobInput.end()){
        cout << "Bad Input." << endl;
        return getInput();
    }
    return in;
}

void Knob::knob(){
    cout << "What is the left side of lights? Enter the positions of the on lights with no spaces." << endl;
    cout << "Enter \"none\" if there are no lights in the left half." << endl;
    string in = getInput();
    if(in == "3456" || in == "1356"){
        cout << "Set the knob to UP" << endl;
    }else if(in == "23456" || in == "135"){
        cout << "Set the knob to the OPPOSITE of UP" << endl;
    }else if(in == "4" || in == "none"){
        cout << "Set the knob to the LEFT of UP" << endl;
    }else if(in == "13456"){
        cout << "Set the knob to the RIGHT of UP" << endl;
    }
}