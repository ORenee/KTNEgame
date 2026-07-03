/**
 * @file Wires.cpp
 * @author Renee Olds
 */

#include "Wires.h"
#include <iostream>
using namespace std;

void Wires::cut(int num){
    cout << "Cut the ";
    switch(num){
        case 1 :
            cout << "first wire." << endl;
            break;
        case 2 :
            cout << "second wire." << endl;
            break;
        case 3 :
            cout << "third wire." << endl;
            break;
        case 4 :
            cout << "fourth wire." << endl;
            break;
        case 5 :
            cout << "fifth wire." << endl;
            break;
        case 6 :
            cout << "last wire." << endl;
            break;
    }
}

bool Wires::threeWires(int red, string last, int blue){
    if(red == 0){
        cut(2);
        return true;
    }else if(last == "white"){
        cut(6);
        return true;
    }else if(blue > 1){
        cout << "Cut the last blue wire." << endl;
        return true;
    }else if(red != -1 && blue != -1){
        cut(6);
        return true;
    }
    return false;
}

bool Wires::fourWires(unique_ptr<Bomb>&bomb, int red, string last, int blue, int yellow){
    if(!bomb->getSerialCode() && red > 1){
        cout << "Cut the last red wire." << endl;
        return true;
    }else if((last == "yellow" && red == 0) || blue == 1){
        cut(1);
        return true;
    }else if(yellow > 1){
        cut(6);
        return true;
    }else if(red != -1 && blue != -1 && yellow != -1){
        cut(2);
        return true;
    }
    return false;
}

bool Wires::fiveWires(unique_ptr<Bomb>&bomb, string last, int black, int red, int yellow){
    if(!bomb->getSerialCode() && last == "black"){
        cut(4);
        return true;
    }else if(red == 1 && yellow > 1){
        cut(1);
        return true;
    }else if(black == 0){
        cut(2);
        return true;
    }else if(red != -1 && black != -1){
        cut(1);
        return true;
    }
    return false;
}

bool Wires::sixWires(unique_ptr<Bomb>&bomb, int yellow, int white, int red){
    if(!bomb->getSerialCode() && yellow == 0){
        cut(3);
        return true;
    }else if(yellow == 1 && white > 1){
        cut(4);
        return true;
    }else if(red == 0){
        cut(6);
        return true;
    }else if(red != -1 && yellow != -1){
        cut(4);
        return true;
    }
    return false;
}

int Wires::checkWireInput(int toCheck, int max){
    while(toCheck > max){
        cout << "Bad Input." << endl;
        toCheck = stoi(thisinput.getUserInput("wires"));
    }
    return toCheck;
}

void Wires::wires(unique_ptr<Bomb>&bomb){
    cout << "How many Wires?" << endl;
    int in = 0;
    in = stoi(thisinput.getUserInput("wires"));
    while(in < 3){
        cout << "Bad Input." << endl;
        in = stoi(thisinput.getUserInput("wires"));
    }
    int red = -1;
    int white = -1;
    int blue = -1;
    int yellow = -1;
    int black = -1;
    string last = "";
    int i = 0;
    switch(in){
        case 3: 
            while(!threeWires(red, last, blue)){
                if(i == 0){
                    cout << "How many red?" << endl;
                    red = checkWireInput(stoi(thisinput.getUserInput("wires")), 3);
                }else if(i == 1){
                    cout << "Is the last wire white?" << endl;
                    if(thisinput.getUserInput("yn") == "y"){
                        last = "white";
                    }
                }else if(i == 2){
                    cout << "How many blue?" << endl;
                    blue = checkWireInput(stoi(thisinput.getUserInput("wires")), 3);
                }else{
                    cout << "Problem occured in three wires" << endl;
                    return;
                }
                i++;
            }
            break;
        case 4:
            while(!fourWires(bomb, red, last, blue, yellow)){
                if(i == 0){
                    cout << "How many red?" << endl;
                    red = checkWireInput(stoi(thisinput.getUserInput("wires")), 4);
                }else if(i == 1){
                    cout << "Is the last wire yellow?" << endl;
                    if(thisinput.getUserInput("yn") == "y"){
                        last = "yellow";
                    }
                }else if(i == 2){
                    cout << "How many blue?" << endl;
                    blue = checkWireInput(stoi(thisinput.getUserInput("wires")), 4);
                }else if(i == 3){
                    cout << "How many yellow?" << endl;
                    yellow = checkWireInput(stoi(thisinput.getUserInput("wires")), 4);
                }else{
                    cout << "Problem occured in four wires" << endl;
                    return;
                }
                i++;
            }
            break;
        case 5:
            while(!fiveWires(bomb, last, black, red, yellow)){
                if(i == 0){
                    cout << "Is the last wire black?" << endl;
                    if(thisinput.getUserInput("yn") == "y"){
                        last = "black";
                    }
                }else if(i == 1){
                    cout << "How many red?" << endl;
                    red = checkWireInput(stoi(thisinput.getUserInput("wires")), 5);
                }else if(i == 2){
                    if(red == 1){
                        cout << "How many yellow?" << endl;
                        yellow = checkWireInput(stoi(thisinput.getUserInput("wires")), 5);
                    }
                }else if(i == 3){
                    cout << "How many black?" << endl;
                    black = checkWireInput(stoi(thisinput.getUserInput("wires")), 5);
                }else{
                    cout << "Problem occured in five wires" << endl;
                    return;
                }
                i++;
            }
            break;
        case 6:
            while(!sixWires(bomb, yellow, white, red)){
                if(i == 0){
                    cout << "How many yellow?" << endl;
                    yellow = stoi(thisinput.getUserInput("wires"));
                }else if(i == 1){
                    if(yellow == 1){
                        cout << "How many white?" << endl;
                        white = stoi(thisinput.getUserInput("wires"));
                    }
                }else if(i == 2){
                    cout << "How many red?" << endl;
                    red = stoi(thisinput.getUserInput("wires"));
                }else{
                    cout << "Problem occured in six wires" << endl;
                    return;
                }
                i++;
            }
            break;
        default: // should never execute
            cout << "invalid wire number" << endl;
    }
}

bool Wires::complicatedWiresKey(unique_ptr<Bomb>&bomb, string color, bool light, bool star){
    if(color == "w"){
        if(star && light){
            if(bomb->getBatteries() >= 2){
                cout << "Cut the wire" << endl;
                return true;
            }
            cout << "Leave the wire" << endl;
        }else if(light && !star){
            cout << "Leave the wire" << endl;
        }else{
            cout << "Cut the wire" << endl;
        }
        return true;
    }else if(color == "b"){
        if(light){
            if(bomb->getPort()){
                cout << "Cut the wire" << endl;
                return true;
            }
            cout << "Leave the wire" << endl;
        }else if(!star && bomb->getSerialCode()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
        return true;
    }else if(color == "r"){
        if(light){
            if(bomb->getBatteries() >= 2){
                    cout << "Cut the wire" << endl;
                    return true;
            }
            cout << "Leave the wire" << endl;
        }else if(star){
            cout << "Cut the wire" << endl;
        }else{
            if(bomb->getSerialCode()){
                cout << "Cut the wire" << endl;
                return true;
            }
            cout << "Leave the wire" << endl;
        }
        return true;
    }else if(color == "s"){
        if(!star){
            if(bomb->getSerialCode()){
                cout << bomb->getSerialCode() << " " << star << endl;
                cout << "Cut the wire" << endl;
                return true;
            }
            cout << "Leave the wire" << endl;
        }else if(bomb->getPort()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
        return true;
    }
    return false;
}

void Wires::complicatedWires(unique_ptr<Bomb>&bomb){
    string wireSpecs = "";
    string color = "";
    bool light;
    bool star;
    bool hasNextWire = true;
    cout << "Input the color (w, r, b, s) followed by whether there is a light (y or n) and whether there is a star (y or n) with no spaces. Input \"exit\" when done." << endl;
    while(hasNextWire){
        wireSpecs = thisinput.getUserInput("complicated");
        light = (wireSpecs.substr(1,1) == "y") ? true : false;
        star = (wireSpecs.substr(2,1) == "y") ? true : false;
        color = wireSpecs.substr(0,1);
        if(!complicatedWiresKey(bomb, color, light, star)){
            cout << "Not a wire combination" << endl;
        }
    }
}

void Wires::redSequence(int red, string pos){
    set<int> aReds = {3, 4, 6, 7, 8};
    set<int> bReds = {2, 5, 7, 8, 9};
    set<int> cReds = {1, 4, 6, 7};
    if(pos == "a"){
        if(aReds.find(red) != aReds.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }else if(pos == "b"){
        if(bReds.find(red) != bReds.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }else if(pos == "c"){
        if(cReds.find(red) != cReds.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }
}

void Wires::blueSequence(int blue, string pos){
    set<int> aBlues = {2, 4, 8, 9};
    set<int> bBlues = {1, 3, 5, 6};
    set<int> cBlues = {2, 6, 7, 8};
    if(pos == "a"){
        if(aBlues.find(blue) != aBlues.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }else if(pos == "b"){
        if(bBlues.find(blue) != bBlues.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }else if(pos == "c"){
        if(cBlues.find(blue) != cBlues.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }
}

void Wires::blackSequence(int black, string pos){
    set<int> aBlacks = {1, 2, 4, 7};
    set<int> bBlacks = {1, 3, 5, 6, 7};
    set<int> cBlacks = {1, 2, 4, 6, 8, 9};
    if(pos == "a"){
        if(aBlacks.find(black) != aBlacks.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }else if(pos == "b"){
        if(bBlacks.find(black) != bBlacks.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }else if(pos == "c"){
        if(cBlacks.find(black) != cBlacks.end()){
            cout << "Cut the wire" << endl;
        }else{
            cout << "Leave the wire" << endl;
        }
    }
}

void Wires::wireSequences(){
    int red = 0;
    int blue = 0;
    int black = 0;
    bool hasNextWire = true;
    string wireSpecs = "";
    cout << "Enter the color (r, b, k) followed by the letter (a, b, or c) with no spaces. Enter \"exit\" when done." << endl;
    while(hasNextWire){
        wireSpecs = thisinput.getUserInput("sequences");
        if(wireSpecs.substr(0, 1) == "r"){
            ++red;
            redSequence(red, wireSpecs.substr(1,1));
        }else if(wireSpecs.substr(0, 1) == "b"){
            ++blue;
            blueSequence(blue, wireSpecs.substr(1,1));
        }else if(wireSpecs.substr(0,1) == "k"){
            ++black;
            blackSequence(black, wireSpecs.substr(1,1));
        }else{
            cout << "bad color" << endl;
        }
    }
}

