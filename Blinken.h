/**
 * @file blinken.h
 * @author Renee Olds
 */

#ifndef BLINKEN_
#define BLINKEN_

#include "Bomb.h"
#include "Input.h"
#include <unordered_map>

class Blinken{
    private:

        Input thisinput;

        //for morse code
        std::unordered_map<std::string, double> words = {{"shell", 3.505}, {"halls", 3.515}, {"slick", 3.522}, {"trick", 3.532}, {"boxes", 3.535}, {"leaks", 3.542}, 
        {"strobe", 3.545}, {"bistro", 3.552}, {"flick", 3.555}, {"bombs", 3.565}, {"break", 3.572}, {"brick", 3.575}, {"steak", 3.582}, {"sting", 3.592}, 
        {"vector", 3.595}, {"beats", 3.6}};

        /**
         * @brief instructions for what to do with the button
         * 
         * @param bomb 
         * @param color the color of the button
         * @param word the word that is on the button
         */
        void buttonKey(std::unique_ptr<Bomb>&bomb, std::string color, std::string word);

        /**
         * @brief traslates a string of . and - into letters for morse code
         * 
         * @param code the string to be translated
         * @return char the coresponding alphebet letter. returns 0 if no letter matches
         */
        char translateMorseCode(std::string code);

    public:

        /**
         * @brief prompts input for the button
         * 
         * @param bomb 
         */
        void button(std::unique_ptr<Bomb>&bomb);

        /**
         * @brief prompts and manages input for simon says
         * 
         * @param bomb 
         */
        void simonSays(std::unique_ptr<Bomb>&bomb);

        /**
         * @brief prompts input for morse code
         * 
         */
        void morseCode();


        /**
         * @brief prompts input for knob
         */
        void knob();

};

#endif