/* 
*  @file main.cpp
*  @author Renee Olds
* morse code doesn't end
done for whos
*/

#include "Bomb.h"
#include "Input.h"
#include "Blinken.h"
#include "Wires.h"
#include "WordMods.h"
#include "ModulesInfo.h"
#include "Maze.h"
#include "Knob.h"
#include <iostream>
#include <memory>
using namespace std;

Bomb* levelSetUp(){
    string in;
    cout << "How many strikes do you get for this level? Enter 0, 1 or 2" << endl;
    getline(cin, in);
    while(in < "0" || in > "2"){
        cout << "Bad number. Enter 0, 1, or 2" << endl;
        getline(cin, in);
    }
    return new Bomb(stoi(in));
}

//for all check functions: if given variable is not defined, prompt for input and define it
void checkBatteries(unique_ptr<Bomb>& bomb, unique_ptr<Input>& thisinput){
    if(!bomb->definedBats()){
        cout << "How many batteries on the bomb?" << endl;
        bomb->setBatteries(stoi(thisinput->getUserInput("initbomb"))); 
    }
}

void checkPort(unique_ptr<Bomb>& bomb, unique_ptr<Input>& thisinput){
    if(!bomb->definedPort()){
        cout << "Is there a port on the bomb? Enter \"y\" or \"n\"" << endl;
        bomb->setPort( (thisinput->getUserInput("yn") == "y") ? true : false ); 
    }
}

void checkCode(unique_ptr<Bomb>& bomb, unique_ptr<Input>& thisinput){
    if(!bomb->definedCode()){
        cout << "What is the last digit of the serial number?" << endl;
        bool isEven = (stoi(thisinput->getUserInput("initbomb")) % 2 == 0) ? true : false;
        bomb->setSerialCode(isEven); 
        cout << bomb->getSerialCode() << endl;
    }
}

void checkVowel(unique_ptr<Bomb>& bomb, unique_ptr<Input>& thisinput){
    if(!bomb->definedVowel()){
        cout << "Does the serial number contain a vowel? Enter \"y\" or \"n\"" << endl;
        bomb->setVowel( (thisinput->getUserInput("yn") == "y") ? true : false ); 
    }
}

void startDefuse(unique_ptr<Bomb>& bomb){
    unique_ptr<Input> thisinput(new Input());
    unique_ptr<Wires> wireMods(new Wires());
    unique_ptr<Blinken> blinken(new Blinken());
    unique_ptr<WordMods> wordMods(new WordMods());
    unique_ptr<Knob> thisknob(new Knob());
    bool cont = true;
    string in;
    cout << "Enter \"info\" at module selection to read about this program and each module. Enter \"info\" at any time to learn about the current module." << endl;
    cout << "At any point, enter \"boom\" to end level or \"exit\" to leave the current module and select another." << endl;
    cout << "Enter \"knob\" at any point or \"kno\" at module selection to resolve knob." << endl;
    while(cont){
        try{
            cout << "Which module? Enter the first three letters of module name." << endl;
            in = thisinput->getUserInput("module");
            if(in == "info"){
                getInfo();
            }else if(in == "wir"){
                checkBatteries(bomb, thisinput);
                checkCode(bomb, thisinput);
                checkPort(bomb, thisinput);
                wireMods->wires(bomb);
            }else if(in == "com"){
                checkBatteries(bomb, thisinput);
                checkCode(bomb, thisinput);
                checkPort(bomb, thisinput);
                wireMods->complicatedWires(bomb);
            }else if(in == "seq"){
                wireMods->wireSequences();
            }else if(in == "but"){
                checkBatteries(bomb, thisinput);
                blinken->button(bomb);
            }else if(in == "mor"){
                blinken->morseCode();
            }else if(in == "sim"){
                checkVowel(bomb, thisinput);
                blinken->simonSays(bomb);
            }else if(in == "who"){
                wordMods->whosOnFirst();
            }else if(in == "mem"){
                wordMods->memory();
            }else if(in == "pas"){
                wordMods->password();
            }else if(in == "key"){
                // add keypad call
            }else if(in == "maz"){
                // add mazes call
            }else if(in == "kno"){
                thisknob->knob();
            }
        }catch(const ModuleEndExcep& e){
            cout << e.what() << endl;
        }
    }
}

void runDefuse(){
    cout << "Welcome." << endl;
    unique_ptr<Bomb> thisbomb(levelSetUp());
    try{
        startDefuse(thisbomb);
    }catch(const LevelEndExcep& e){
        string in;
        cout << e.what();
        cout << ". Would you like to play again? (y/n)" << endl;
        getline(cin, in);
        while(in != "y" && in != "n"){
            cout << "Bad input. Play again? (y/n)" << endl;
            getline(cin, in);
        }
        if(in == "y"){
            runDefuse();
        }
    }
}

int main(){
    runDefuse();
    //solveMaze();
}

