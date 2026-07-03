/**
 * @file Bomb.cpp
 * @author Renee Olds
 */

#include "Bomb.h"

Bomb::Bomb(int str){
    strikes = str;
}

void Bomb::setSerialCode(bool sc){
    serialCode = (sc) ? 1 : 0;
}

bool Bomb::getSerialCode(){
    return (serialCode == 1) ? true : false;
}

void Bomb::setBatteries(int bat){
    batteries = bat;
}

int Bomb::getBatteries(){
    return batteries;
}

void Bomb::setPort(bool p){
    port = (p) ? 1 : 0;
}

bool Bomb::getPort(){
    return (port == 1) ? true : false;
}

void Bomb::setVowel(bool v){
    hasVowel = (v) ? 1 : 0;
}

bool Bomb::getVowel(){
    return (hasVowel == 1) ? true : false;
}

int Bomb::getStrikes(){
    return strikes;
}

bool Bomb::definedCode(){
    return (serialCode == -1) ? false : true;
}

bool Bomb::definedBats(){
    return (batteries == -1) ? false : true;
}

bool Bomb::definedPort(){
    return (port == -1) ? false : true;
}

bool Bomb::definedVowel(){
    return (hasVowel == -1) ? false : true;
}