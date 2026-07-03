/**
 * @file WordMods.cpp
 * @author Renee Olds
 */

#include "WordMods.h"
#include <iostream>
#include <algorithm>
using namespace std;

string WordMods::findPos(int num){
    switch(num){
        case 1 :
            return "top left";
            break;
        case 2 :
            return "top right";
            break;
        case 3 :
            return "middle left";
            break;
        case 4 :
            return "middle right";
            break;
        case 5 :
            return "bottom left";
            break;
        case 6 :
            return "bottom right";
            break;
        default :
            return "invalid num";
    }
}

bool WordMods::isValidInput(string map, string in){
    bool isValid; 
    try{
        if(map == "step1"){
            step1.at(in);
        }else{
            step2.at(in);
        }
        isValid = true;
    }catch(const out_of_range& oor){
        isValid = false;
    }
    return isValid;
}

void WordMods::whosOnFirst(){
    string in;
    vector<string> itemsToPrint;
    cout << "Input the top word with no caps. If blank, input \"none\". Input \"exit\" to exit module." << endl;
    getline(cin, in);
    if(in == "exit"){
        throw ModuleEndExcep("Exiting Who's on First");
    }else if(in == "end"){
        throw LevelEndExcep("Level Ended");
    }
    while(!isValidInput("step1", in)){ 
        cout << "Invalid word" << endl;
        getline(cin, in);
        if(in == "exit"){
            throw ModuleEndExcep("Exiting Who's on First");
        }else if(in == "end"){
            throw LevelEndExcep("Level Ended");
        }
    }

    cout << "What is the word in the " << findPos(step1.at(in)) << "?" << endl;
    getline(cin, in);
    if(in == "exit"){
        throw ModuleEndExcep("Exiting Who's on First");
    }else if(in == "end"){
        throw LevelEndExcep("Level Ended");
    }
    while(!isValidInput("step2", in)){
        cout << "Invalid word1" << endl;
        getline(cin, in);
        if(in == "exit"){
            throw ModuleEndExcep("Exiting Who's on First");
        }else if(in == "end"){
            throw LevelEndExcep("Level Ended");
        }
    }

    itemsToPrint = step2.at(in);
    cout << "Click the word that appears first." << endl;
    for(int i = 0; i < itemsToPrint.size(); ++i){
        cout << itemsToPrint[i] << " : ";
    }
    cout << endl;

    whosOnFirst(); // recursive: base case when user types exit

}

void WordMods::password(){
    vector<string> theseWords = passwordList;
    cout << "Input all letters in position with no spaces. Input \"exit\" to exit" << endl;
    string in;
    int l = 1;
    bool foundWord = false;
    while(!foundWord && l < 6){
        cout << "Enter position " << l << " letters" << endl;
        getline(cin, in);
        if(in == "exit"){
            throw ModuleEndExcep("Exiting Password");
        }else if(in == "end"){
            throw LevelEndExcep("Level Ended");
        }
        bool hasletter = false;
        for(int i = theseWords.size()-1; i >= 0; --i){
            for(char s : in){
                if(theseWords[i].at(l-1) == s){
                    hasletter = true;
                }
            }
            if(!hasletter){
                theseWords.erase(theseWords.begin()+i);
            }
            hasletter = false;
        }
        if(theseWords.size() == 1){
            foundWord = true;
            cout << "Set to " << theseWords.front() << endl;
        }
        if(theseWords.empty()){
            foundWord = true;
            cout << "No word fits. Recheck each letter" << endl;
            password();
        }
        ++l;
    }
}

void WordMods::memory(){
    int curStage = 1;
    int stage1[2]; // [0] = position , [1] = label
    int stage2[2];
    int stage3[2];
    int stage4[2];
    string in;
    int dis;
    while(curStage < 6){
        cout << "Input the top number" << endl;
        in = thisinput.getUserInput("memory");
        while(in.find_first_not_of("1234") != string::npos){
            cout << "Invalid input. Enter 1, 2, 3, or 4" << endl;
            in = thisinput.getUserInput("memory");
        }
        dis = stoi(in);
        cout << "Press button ";
        bool needLabel = true;
        switch(curStage){ //defaults in inner switch statments should never execute
            case 1 :
                switch(dis){
                    case 1 :
                        cout << "in position 2";
                        stage1[0] = 2;
                        break;
                    case 2 :
                        cout << "in position 2";
                        stage1[0] = 2;
                        break;
                    case 3 :
                        cout << "in position 3";
                        stage1[0] = 3;
                        break;
                    case 4 :
                        cout << "in position 4";
                        stage1[0] = 4;
                        break;
                    default :
                        cout << "Bad input." << endl;
                        --curStage;
                }
                cout << ". What was that button labeled?" << endl;
                stage1[1] = stoi(thisinput.getUserInput("memory"));
                break;
            case 2 :
                switch(dis){
                    case 1 :
                        cout << "labeled 4";
                        stage2[1] = 4;
                        needLabel = false;
                        break;
                    case 2 :
                        cout << "in position " << stage1[0];
                        stage2[0] = stage1[0];
                        break;
                    case 3 :
                        cout << "in position 1";
                        stage2[0] = 1;
                        break;
                    case 4 :
                        cout << "in position " << stage1[0];
                        stage2[0] = stage1[0];
                        break;
                    default :
                        cout << "Bad input." << endl;
                        --curStage;
                }
                if(needLabel){
                    cout << ". What was that button labeled?" << endl;
                    stage2[1] = stoi(thisinput.getUserInput("memory"));
                }else{
                    cout << ". What was that button's position?" << endl;
                    stage2[0] = stoi(thisinput.getUserInput("memory"));
                }
                break;
            case 3 :
                switch(dis){
                    case 1 :
                        cout << "labeled " << stage2[1];
                        stage3[1] = stage2[1];
                        needLabel = false;
                        break;
                    case 2 :
                        cout << "labeled " << stage1[1];
                        stage3[1] = stage1[1];
                        needLabel = false;
                        break;
                    case 3 :
                        cout << "in position 3";
                        stage3[0] = 3;
                        break;
                    case 4 :
                        cout << "labeled 4";
                        stage3[1] = 4;
                        needLabel = false;
                        break;
                    default :
                        cout << "Bad input." << endl;
                        --curStage;
                }
                if(needLabel){
                    cout << ". What was that button labeled?" << endl;
                    stage3[1] = stoi(thisinput.getUserInput("memory"));
                }else{
                    cout << ". What was that button's position?" << endl;
                    stage3[0] = stoi(thisinput.getUserInput("memory"));
                }
                break;
            case 4 :
                switch(dis){
                    case 1 :
                        cout << "in position " << stage1[0];
                        stage4[0] = stage1[0];
                        break;
                    case 2 :
                        cout << "in position 1";
                        stage4[0] = 1;
                        break;
                    case 3 :
                        cout << "in position " << stage2[0];
                        stage4[0] = stage2[0];
                        break;
                    case 4 :
                        cout << "in position " << stage2[0];
                        stage4[0] = stage2[0];
                        break;
                    default :
                        cout << "Bad input." << endl;
                        --curStage;
                }
                if(needLabel){
                    cout << ". What was that button labeled?" << endl;
                    stage4[1] = stoi(thisinput.getUserInput("memory"));
                }else{
                    cout << ". What was that button's position?" << endl;
                    stage4[0] = stoi(thisinput.getUserInput("memory"));
                }
                break;
            case 5 :
                switch(dis){
                    case 1 :
                        cout << "labeled " << stage1[1] << "." << endl;
                        break;
                    case 2 :
                        cout << "labeled " << stage2[1] << "." << endl;
                        break;
                    case 3 :
                        cout << "labeled " << stage4[1] << "." << endl;
                        break;
                    case 4 :
                        cout << "labeled " << stage3[1] << "." << endl;
                        break;
                    default :
                        cout << "Bad input." << endl;
                        --curStage;
                }   
        }
    ++curStage;
    }

}