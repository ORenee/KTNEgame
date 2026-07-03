/**
 * @file ModulesInfo.cpp
 * @author Renee Olds
 */

#include "ModulesInfo.h"
#include <iostream>
using namespace std;



void getInfo(){
    cout << "Enter the first three letters of the module you would like to learn about." << endl;
    cout << "Enter \"general\" to learn about module selection input and general program information." << endl;
    string in;
    getline(cin, in);
    if(in == "general"){
        generalInfo();
    }else if(in == "wir"){
        wiresInfo();
    }else if(in == "com"){
        complicatedInfo();
    }else if(in == "seq"){
        sequencesInfo();
    }else if(in == "but"){
        buttonInfo();
    }else if(in == "mor"){
        morseCodeInfo();
    }else if(in == "sim"){
        simonSaysInfo();
    }else if(in == "who"){
        whosOnFirstInfo();
    }else if(in == "mem"){
        memoryInfo();
    }else if(in == "pas"){
        passwordsInfo();
    }else if(in == "key"){
        keypadInfo();
    }else if(in == "maz"){
        mazesInfo();
    }else if(in == "kno"){
        knobInfo();
    }else{
        throw ModuleEndExcep("Exiting Module Info");
    }
    cout << "Would you like to learn about another module?" << endl;
    getline(cin, in);
    while(in != "y" && in != "n"){
        cout << "Bad Input." << endl;
        getline(cin, in);
    }
    if(in == "y"){
        getInfo();
    }
}

void generalInfo(){
    cout << "#1 : Please tell me if you see any errors" << endl;
    cout << "#2 : Here is a list of modules ->" << endl;
    cout << "   wires, complicated wires, wire sequences, button, keypad, simon says, who's on first, memory, morse code," << endl;
    cout << "   mazes, passwords, knob. Enter the first three letters of a module during module selection (or \"seq\" for wire sequences)." << endl;
    cout << "#3 : When prompted for colors, \"k\" always means black and \"b\" always means blue." << endl;
    cout << "#4 : The port is a parallel port. It has two rows of small circular input holes." << endl;
    cout << "#5 : This program assumes you know what needy modules are. If you don't, input \"kno\" when prompted for modules' info." << endl;
}

void wiresInfo(){
    cout << "This module is 3-6 horizontal wires with various colors." << endl;
    cout << "Input is self-explanitory." << endl;
}

void complicatedInfo(){
    cout << "This module is 3-6 vertical wires with a light above each and a star sticker below each." << endl;
    cout << "Input :" << endl;
    cout << "   The color - either white, red, blue, or spiral. If a wire is a spiral of white and another color (either red or blue)," << endl;
    cout << "   enter the color (so either red or blue). A wire that is a blue and red spiral should be inputed as spiral." << endl;
    cout << "   The light - either the light above the wire is on or off. Input y if on and n if off." << endl;
    cout << "   The star - either there is a star-looking shape beneath the wire or there isn't. Input y if there is and n if not." << endl;
    cout << "Input should look like this : \"wyn\" (white, light, no star), or \"sny\" (red/blue spiral, no light, star)." << endl;
}

void sequencesInfo(){
    cout << "This module has up to three wires crossing from a number to a letter. After managing each wire, press the down arrow to move on." << endl;
    cout << "Input : " << endl;
    cout << "   The color - either red, blue, or black (r, b, or k)." << endl;
    cout << "   The letter - what letter the wire is connected to." << endl;
    cout << "Do not quit and come back to this module. Do it all in one go. " << endl;
}

void buttonInfo(){
    cout << "!! This program does not take into account the case of having more than two batteries and a FRK indicator, meaning this program will be wrong for that scenario !!" << endl;
    cout << "This module has a colored button labeled with a word and a vertical strip next to it." << endl;
    cout << "Input : " << endl;
    cout << "   The color - The color of the button is blue, white, yellow, red, or black (b, w, y, r, or k)." << endl;
    cout << "   The word - The word on the button is Hold, Abort, Detonate, or Press (h, a, d, or p)." << endl;
    cout << "   Later, enter the color of the blinking strip next to the button." << endl;
}

void keypadInfo(){
    cout << "Module not implemented yet" << endl;
}

void simonSaysInfo(){
    cout << "This module is four colored diamonds. One of them starts blinking." << endl;
    cout << "Input is self-explanitory. This program will print what color the user should input for each blinking color to complete simon says." << endl;
    cout << "If strikes occur while doing this module, the colors will change. Restart the module to have accurate colors." << endl;
}

void whosOnFirstInfo(){
    cout << "This module has one word on top and six words beneath it." << endl;
    cout << "Input is self-explanitory." << endl;
}

void memoryInfo(){
    cout << "This module is one number on top and four numbers beneath it." << endl;
    cout << "Input is self-explanitory. Remember the position or number you pressed so you can accurately respond to the program." << endl;
    cout << "If you make a mistake doing this module, restart the module." << endl;
}

void morseCodeInfo(){
    cout << "This module has a blinking light reading out morse code in the top left. There is a number starting at 3.500 in the center." << endl;
    cout << "Input the morse code as accurately as possible. The program prompts you again if it is innaccurate." << endl;
}

void mazesInfo(){
    cout << "Module not implemented yet" << endl;
}

void passwordsInfo(){
    cout << "This module has five letters, each with arrows above and below." << endl;
    cout << "Input : " << endl;
    cout << "   Scroll through the letter it prompts for with the arrows. When given a word, spell it out and press submit." << endl;
    cout << "Be careful to type the correct letters. Restart if errors occur." << endl;
}

void knobInfo(){
    cout << "This module is a needy module. Needy modules requre the defuser to interact with them every now and then." << endl;
    cout << "Input : " << endl;
    cout << "   The positions of the left side's on lights. Only look at the left six light when inputing." << endl;
    cout << "   Starting from the top left and going along the top row is positiong 1, 2, and 3. The bottom row is 4, 5, and 6." << endl;
    cout << "Input should look like this : \"135\" (first and third light on top row, second light on bottom row)." << endl;
    cout << "This module can be accessed in this program from anywhere by typing \"knob\". Enter \"kno\" to select it during module selection." << endl;
    cout << "Other needy modules are Venting Gas (respond using yes/no) and Capacitor Discharge (hold the lever to increase count)." << endl;
}