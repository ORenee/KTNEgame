/**
 * @file ModuleEndExcep.cpp
 * @author Renee Olds
 */


#include "ModuleEndExcep.h"

ModuleEndExcep::ModuleEndExcep(const std::string& message)
   : std::runtime_error(message) {
}