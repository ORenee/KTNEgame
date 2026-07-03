/**
 * @file Bomb.h
 * @author Renee Olds
 */

#ifndef BOMB_
#define BOMB_

#include <string>

class Bomb {
    private:
        int strikes;
        int serialCode = -1;
        int batteries = -1;
        int port = -1;
        int hasVowel = -1;

    public:
        /**default constructor */
        Bomb() = default;

        /** constructor
         * 
         * @pre 0 <= str <= 2
         * @post strikes = str
         * @param str 
         */
        Bomb(int str);

        /** default destructor */
        ~Bomb() = default;

        /**
         * sets the serial code to true (even) or false (odd)
         * 
         * @param sc the bool value of the serial code
         */
        void setSerialCode(bool sc);

        /**
         * @return whether the serial code is even (true) or false (odd)
         */
        bool getSerialCode();

        /**
         * sets the amount of batteries
         * 
         * @param bat the amount to set batteries to
         */
        void setBatteries(int bat);

        /**
         * @return the number of batteries
         */
        int getBatteries();

        /**
         * sets the port to whether the bomb has it or not
         * 
         * @param port the value to set port to
         */
        void setPort(bool p);

        /**
         * @return whether there is a port (true) or not (false)
         */
        bool getPort();

        /**
         * sets the port to whether the bomb has it or not
         * 
         * @param port the value to set port to
         */
        void setVowel(bool v);

        /**
         * @return whether there is a port (true) or not (false)
         */
        bool getVowel();

        /**
         * @return int the number of strikes allowed for this level
         */
        int getStrikes();


        /**
         * @return whether serial code is defined or not
         */
        bool definedCode();

        /**
         * @return whether batteries is defined or not
         */
        bool definedBats();


        /**
         * @return whether port is defined or not
         */
        bool definedPort();


        /**
         * @return whether vowel is defined or not
         */
        bool definedVowel();

};
#endif