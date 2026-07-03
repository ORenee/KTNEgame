/**
 * @file wordMods.h
 * @author Renee Olds
 */

#ifndef WORD_MODS_
#define WORD_MODS_

#include "Bomb.h"
#include "Input.h"
#include <unordered_map>
#include <vector>
#include <array>

class WordMods {
    private:

        Input thisinput;

        // map of words for whos on first step 1 - int coresponds to position reading left to right
        std::unordered_map<std::string, int> step1 = {{"yes", 3}, {"first", 2}, {"display", 6}, {"okay", 2}, {"says", 6}, {"nothing", 3}, {"none", 5}, {"blank", 4},
            {"no", 6}, {"led", 3}, {"lead", 6}, {"read", 4}, {"red", 4}, {"reed", 4}, {"leed", 5}, {"hold on", 6}, {"you", 4}, {"you are", 6}, {"your", 4},
            {"you're", 4}, {"ur", 1}, {"there", 6}, {"they're", 5}, {"their", 4}, {"they are", 3}, {"see", 6}, {"c", 2}, {"cee", 6}
        };

        //map for whos on first step 2 - string is for identification and array is words that are read to user
        std::unordered_map<std::string, std::vector<std::string>> step2 = {
            {"ready",   {"yes", "okay", "what", "middle", "left", "press", "right", "blank", "ready"}},
            {"first",   {"left", "okay", "yes", "middle", "no", "right", "nothing", "uhhh", "wait", "ready", "blank", "what", "press", "first"}},
            {"no",      {"blank", "uhhh", "wait", "first", "what", "ready", "right", "yes", "nothing", "left", "press", "okay", "no"}},
            {"blank",   {"wait", "right", "okay", "middle", "blank"}},
            {"nothing", {"uhhh", "right", "okay", "middle", "yes", "blank", "no", "press", "left", "what", "wait", "first", "nothing"}},
            {"yes",     {"okay", "right", "uhhh", "middle", "first", "what", "press", "ready", "nothing", "yes"}},
            {"what",    {"uhhh", "what"}},
            {"uhhh",    {"ready", "nothing", "left", "what", "okay", "yes", "right", "no", "press", "blank", "uhhh"}},
            {"left",    {"right", "left"}},
            {"right",   {"yes", "nothing", "ready", "press", "no", "wait", "what", "right"}},
            {"middle",  {"blank", "ready", "okay", "what", "nothing", "press", "no", "wait", "left", "middle"}},
            {"okay",    {"middle", "no", "first", "yes", "uhhh", "nothing", "wait", "okay"}},
            {"wait",    {"uhhh", "no", "blank", "okay", "yes", "left", "first", "press", "what", "wait"}},
            {"press",   {"right", "middle", "yes", "ready", "press"}},
            {"you",     {"sure", "you are", "your", "you're", "next", "uh huh", "ur", "hold", "what?", "you"}},
            {"you are", {"your", "next", "like", "uh huh", "what?", "done", "uh uh", "hold", "you", "u", "you're", "sure", "ur", "you are"}},
            {"your",    {"uh uh", "you are", "uh huh", "your"}},
            {"you're",  {"you", "you're"}},
            {"ur",      {"done", "u", "ur"}},
            {"u",       {"uh huh", "sure", "next", "what?", "you're", "ur", "uh uh", "done", "u"}},
            {"uh huh",   {"uh huh"}},
            {"uh uh",    {"ur", "u", "you are", "you're", "next", "uh uh"}},
            {"what?",   {"you", "hold", "you're", "your", "u", "done", "uh uh", "like", "you are", "uh huh", "ur", "next", "next", "what?"}},
            {"done",    {"sure", "uh huh", "next", "what?", "your", "ur", "you're", "hold", "like", "you", "u", "you are", "uh uh", "done"}},
            {"next",    {"what?", "uh huh", "uh uh", "your", "hold", "sure", "next"}},
            {"hold",    {"you are", "u", "done", "uh uh", "you", "ur", "sure", "what?", "you're", "next", "hold"}},
            {"sure",    {"you are", "done", "like", "you're", "you", "hold", "uh huh", "ur", "sure"}},
            {"like",    {"you're", "next", "u", "ur", "hold", "done", "uh uh", "what?", "uh huh", "you", "like"}}
        };

        //list of possible words for passwords
        std::vector<std::string> passwordList = {"about", "after", "again", "below", "could", "every", "first", "found", "great", "house", "large", 
            "learn", "never", "other", "place", "plant", "point", "right", "small", "sound", "spell", "still", "study", "their", "there", 
            "these", "thing", "think", "three", "water", "where", "which", "world", "would", "write"};

        /**
         * @brief find the string that correlates to the int position for whosOnFirst
         * 
         * @param s 
         * @return string the position of the word user should input
         */
        std::string findPos(int num);

        /**
         * @brief checks if input is valid for whosOnFirst maps
         * 
         * @param in 
         * @param map
         * @return if in is in the map
         */
        bool isValidInput(std::string map, std::string in);

    public:

        /**
         * @brief prompts input for whos on first
         * 
         * @throws levelEndExcep if input says to exit
         */
        void whosOnFirst();

        void password();

        void memory();

};

#endif