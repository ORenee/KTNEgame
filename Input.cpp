/**
 * @file Input.cpp
 * @author Renee Olds
 */

#include "Input.h"
#include "Knob.h"
#include <iostream>
using namespace std;


string Input::getUserInput(string module){
    string in;
    getline(cin, in);
    bool badInput = false;
    if(in == "boom"){
        throw LevelEndExcep("Level Ended");
    }else if(in == "exit" && module != "module"){
        throw ModuleEndExcep("Exiting Module");
    }else if(in == "knob"){
        Knob thisknob;
        thisknob.knob();
        cout << "Input needed for previous prompt. Scroll up to view" << endl;
        return getUserInput(module);
    }
    if(module == "module"){
        if(modInput.find(in) == modInput.end()){
            badInput = true;
        }
    }else if(module == "info"){
        if(modInput.find(in) == modInput.end() && in != "general"){
            badInput = true;
        }
    }else if(module == "yn"){
        if(ynInput.find(in) == ynInput.end()){
            badInput = true;
        }
    }else if(module == "initbomb"){
        if(initBombInput.find(in) == initBombInput.end()){
            badInput = true;
        }
    }else if(module == "wires"){
        if(wiresInput.find(in) == wiresInput.end()){
            badInput = true;
        }
        if(in == "info"){
            wiresInfo();
            return getUserInput(module);
        }
    }else if(module == "complicated"){
        if(coWiresInput.find(in) == coWiresInput.end()){
            badInput = true;
        }
        if(in == "info"){
            complicatedInfo();
            return getUserInput(module);
        }
    }else if(module == "sequences"){
        if(wireSeqInput.find(in) == wireSeqInput.end()){
            badInput = true;
        }
        if(in == "info"){
            sequencesInfo();
            return getUserInput(module);
        }
    }else if(module == "button"){
        if(buttonInput.find(in) == buttonInput.end()){
            badInput = true;
        }
        if(in == "info"){
            buttonInfo();
            return getUserInput(module);
        }
    }else if(module == "buttoncolor"){
        if(buttonCInput.find(in) == buttonCInput.end()){
            badInput = true;
        }
        if(in == "info"){
            buttonInfo();
            return getUserInput(module);
        }
    }else if(module == "strikes"){
        if(strikes.find(in) == strikes.end()){
            badInput = true;
        }
    }else if(module == "morsecode"){
        if(in.find_first_of(".") == string::npos && in.find_first_of("-") == string::npos){
            badInput = true;
        }
        if(in == "info"){
            morseCodeInfo();
            return getUserInput(module);
        }
    }else if(module == "memory"){
        if(memoryInput.find(in) == memoryInput.end()){
            badInput = true;
        }
        if(in == "info"){
            memoryInfo();
            return getUserInput(module);
        }
    }else{
        cout << "No module fits" << endl;
        throw LevelEndExcep("exit from getUserInput");
    }
    if(badInput){
        cout << "Bad Input." << endl;
        return getUserInput(module);
    }
    return in;
}