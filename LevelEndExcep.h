/**
 * @file LevelEndExcep.h
 * @author Renee Olds 
 * 
 */

#ifndef LEVEL_END_EXCEP
#define LEVEL_END_EXCEP

#include <stdexcept>
#include <string>

/** @class LevelEndExcep LevelEndExcep.h "LevelEndExcep.h"
 *
 *  Specification for when the program terminates*/
class LevelEndExcep : public std::runtime_error {
public:
   explicit LevelEndExcep(const std::string& message = "");

   virtual ~LevelEndExcep() noexcept = default;
};

#endif