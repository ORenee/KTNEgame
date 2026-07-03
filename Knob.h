/**
 * @file Knob.h
 * @author Renee Olds
 */

#ifndef KNOB_
#define KNOB_

#include <unordered_set>
#include <string>

/**
 * @brief Seperate class for Knob only
 *  Self sufficient input to protect against an infinite #include loop from Input calling on Knob and Knob needing Input
 */
class Knob{
    private:
        
        std::unordered_set<std::string> knobInput = {"3456", "1356", "23456", "135", "4", "none", "13456"};

        /**
         * @brief similar to input class but only for knob
         * 
         * @return string the user input
         */
        std::string getInput();

    public:

        /**
         * @brief resolves knob
         */
        void knob();
};

#endif