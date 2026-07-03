/**
 * @file Wires.h
 * @author Renee olds
 */

#ifndef WIRES_
#define WIRES_

#include "Bomb.h"
#include "Input.h"
#include <set>
using namespace std;

class Wires {
    private:

        Input thisinput;

        /**
         * @param num prints to cut wire number num
         */
        void cut(int num);

        /**
         * @brief steps for 3 normal wires
         * 
         * @param the wire info needed to find which to cut
         * 
         * @return true if it succeeds in finding a case, false if not
         */
        bool threeWires(int red, string last, int blue);

        /**
         * @brief steps for 4 normal wires
         * 
         * @param wire info needed to find which to cut
         * 
         * @return true if it succeeds in finding a case, false if not
         */
        bool fourWires(std::unique_ptr<Bomb>&bomb, int red, string last, int blue, int yellow);

        /**
         * @brief steps for 5 normal wires
         * 
         * @param wire info needed to find which to cut
         * 
         * @return true if it succeeds in finding a case, false if not
         */
        bool fiveWires(std::unique_ptr<Bomb>&bomb, string last, int black, int red, int yellow);

        /**
         * @brief steps for 6 normal wires
         * 
         * @param wire info needed to find which to cut 
         * 
         * @return true if it succeeds in finding a case, false if not
         */
        bool sixWires(std::unique_ptr<Bomb>&bomb, int yellow, int white, int red);

        /**
         * @brief varifies wires input
         * 
         * @param toCheck the int to check if valid
         * @param max the max possible for toCheck
         * @return the value user is giving
         */
        int checkWireInput(int toCheck, int max);

        /**
         * @brief the key for complicated wires
         * 
         * @param bomb 
         * @param color 
         * @param light 
         * @param star 
         */
        bool complicatedWiresKey(std::unique_ptr<Bomb>&bomb, string color, bool light, bool star);

        /**
         * @brief the red counter for wire sequences
         * 
         * @param red 
         * @param pos 
         */
        void redSequence(int red, string pos);

        /**
         * @brief the blue counter for wire sequences
         * 
         * @param blue 
         * @param pos 
         */
        void blueSequence(int blue, string pos);

        /**
         * @brief the black counter for wire sequences
         * 
         * @param black 
         * @param pos 
         */
        void blackSequence(int black, string pos);

    public:

        /**
         * @brief prompts input for normal wires
         * 
         * @param bomb 
         */
        void wires(std::unique_ptr<Bomb>&bomb);
        
        /**
         * @brief prompts input for complicated wires
         * 
         * @param bomb 
         */
        void complicatedWires(std::unique_ptr<Bomb>&bomb);

        /**
         * @brief prompts input for wire sequences
         * 
         */
        void wireSequences();
};

#endif