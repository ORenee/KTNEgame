/**
 * @file blinken.cpp
 * @author Renee Olds
 */

#include "Blinken.h"
#include <iostream>
using namespace std;

void Blinken::buttonKey(unique_ptr<Bomb>&bomb, string color, string word){
    bool hold;
    if(color == "b" && word == "a"){
        hold = true;
    }else if(word == "d" && bomb->getBatteries() > 1){
        hold = false;
    }else if(color == "y"){
        hold = true;
    }else if(color == "r" && word == "h"){
        hold = false;
    }else{
        hold = true;
    }
    if(hold){
        cout << "Hold button. What color is the strip? (b, w, y, or r)" << endl;
        string in = thisinput.getUserInput("buttoncolor");
        if(in == "b"){
            cout << "Release when timer includes a 4" << endl;
        }else if(in == "y"){
            cout << "Release when timer includes a 5" << endl;
        }else{
            cout << "Release when timer includes a 1" << endl;
        }
    }else{
        cout << "Press and release" << endl;
    }
}

void Blinken::button(unique_ptr<Bomb>&bomb){
    string color = "";
    string word = "";
    string input;
    cout << "Input the color (b, w, y, r, or k) followed by the word on it(h, a, d, or p) with no spaces." << endl;
    input = thisinput.getUserInput("button");
    color = input.substr(0,1);
    word = input.substr(1);
    buttonKey(bomb, color, word);
}

void Blinken::simonSays(unique_ptr<Bomb>&bomb){
    string colors [4] = {"red", "blue", "green", "yellow"};
    string vowel0 [4] = {"blue", "red", "yellow", "green"};
    string vowel1 [4] = {"yellow", "green", "blue", "red"};
    string vowel2 [4] = {"green", "red", "yellow", "blue"};
    string no0 [4] = {"blue", "yellow", "green", "red"};
    string no1 [4] = {"red", "blue", "yellow", "green"};
    string no2 [4] = {"yellow", "green", "blue", "red"};
    int colorCase = 0; //based on how many strikes
    if(bomb->getStrikes() > 0){
        cout << "How many strikes?" << endl;
        int in = stoi(thisinput.getUserInput("strikes")); 
        while(in > bomb->getStrikes()){
            cout << "Bad Input." << endl;
            in = stoi(thisinput.getUserInput("strikes"));
        }
        colorCase = in;
    }
    switch(colorCase){
        case 0 :
            for(int i = 0; i < 4; i++){
                if(bomb->getVowel()){
                    cout << colors[i] << " : " << vowel0[i] << endl;
                }else{
                    cout << colors[i] << " : " << no0[i] << endl;
                }
            }
            break;
        case 1 :
            for(int i = 0; i < 4; i++){
                if(bomb->getVowel()){
                    cout << colors[i] << " : " << vowel1[i] << endl;
                }else{
                    cout << colors[i] << " : " << no1[i] << endl;
                }
            }
            break;
        case 2 :
            for(int i = 0; i < 4; i++){
                if(bomb->getVowel()){
                    cout << colors[i] << " : " << vowel2[i] << endl;
                }else{
                    cout << colors[i] << " : " << no2[i] << endl;
                }
            }
            break;
    }
}

char Blinken::translateMorseCode(string code){
    if(code == ".-"){
        return 'a';
    }else if(code == "-..."){
        return 'b';
    }else if(code == "-.-."){
        return 'c';
    }else if(code == "."){
        return 'e';
    }else if(code == "..-."){
        return 'f';
    }else if(code == "--."){
        return 'g';
    }else if(code == "...."){
        return 'h';
    }else if(code == ".."){
        return 'i';
    }else if(code == "-.-"){
        return 'k';
    }else if(code == ".-.."){
        return 'l';
    }else if(code == "--"){
        return 'm';
    }else if(code == "-."){
        return 'n';
    }else if(code == "---"){
        return 'o';
    }else if(code == ".-."){
        return 'r';
    }else if(code == "..."){
        return 's';
    }else if(code == "-"){
        return 't';
    }else if(code == "...-"){
        return 'v';
    }else if(code == "-..-"){
        return 'x';
    }else{
        cout << "Not a letter." << endl;
        return '0';
    }
}

void Blinken::morseCode(){
    unordered_map<string, double> posWords = words;
    bool foundWord = false;
    cout << "Input using . or - with no spaces." << endl;
    int i = 1;
    char letter = '0';
    bool isLetter;
    while(!foundWord && i < 7){
        isLetter = false;
        while(!isLetter){
            cout << "Enter letter " << i << endl;
            letter = translateMorseCode(thisinput.getUserInput("morsecode"));
            if(letter != '0'){
                isLetter = true;
            }else{
                isLetter = false;
            }
        }
        for(auto& s : words){
            if(s.first.at(i-1) != letter){
                posWords.erase(s.first);
            }
        }
        i++;
        if(posWords.size() == 1){
            foundWord = true;
            for(auto& w : posWords){
                cout << "Set to " << w.second << endl;
            }
        }
        if(posWords.empty()){
            cout << "No word fits. Recheck each letter." << endl;
            morseCode();
        }
    }
}