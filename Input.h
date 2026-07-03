/**
 * @file Input.h
 * @author Renee Olds
 */

#ifndef INPUT_
#define INPUT_

#include "LevelEndExcep.h"
#include "ModuleEndExcep.h"
#include "ModulesInfo.h"
#include <vector>
#include <stdexcept>
#include <unordered_set>
#include <memory>

class Input {
    private:

        std::unordered_set<std::string> modInput = {"wir", "com", "seq", "but", "key", "sim", "who", "mem", "mor", "maz", "pas", "kno", "info"};

        std::unordered_set<std::string> ynInput = {"y", "n"};

        std::unordered_set<std::string> wiresInput = {"0", "1", "2", "3", "4", "5", "6", "info"};

        // complicated wires
        std::unordered_set<std::string> coWiresInput = {"wyy", "wyn", "wny", "wnn","ryy", "ryn", "rny", 
        "rnn", "byy", "byn", "bny", "bnn", "syy", "syn", "sny", "snn", "info"};

        std::unordered_set<std::string> wireSeqInput = {"ra", "rb", "rc", "ba", "bb", "bc", "ka", "kb", "kc", "info"};

        // button's color and text
        std::unordered_set<std::string> buttonInput = {"ba", "bd", "bh", "bp", "ra", "rd", "rh", "rp", "wa", "wd", "wh", "wp",
            "ya", "yd", "yh", "yp", "ka", "kd", "kh", "kp", "info"};

        // for button's colored strip
        std::unordered_set<std::string> buttonCInput = {"b", "w", "y", "r", "info"};

        std::unordered_set<std::string> strikes = {"0", "1", "2"};

        std::unordered_set<std::string> memoryInput = {"1", "2", "3", "4", "info"};

        std::unordered_set<std::string> initBombInput = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    public:

        Input() = default;

        ~Input() = default;

        /**
         * manages all user input 
         * 
         * @param module the input will be checked with this module's set of good input
         * @return string the user's input
         * @throws levelEndExep when input in given to cancel the program
         */
        std::string getUserInput(std::string module);   
   

};

#endif