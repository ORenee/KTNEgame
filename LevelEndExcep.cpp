/**
 * @file LevelEndExcep.cpp
 * @author Renee Olds
 */


#include "LevelEndExcep.h"

LevelEndExcep::LevelEndExcep(const std::string& message)
   : std::runtime_error(message) {
}