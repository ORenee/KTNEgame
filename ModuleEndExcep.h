/**
 * @file ModuleEndExcep.h
 * @author Renee Olds 
 * 
 */

#ifndef MODULE_END_EXCEP
#define MODULE_END_EXCEP

#include <stdexcept>
#include <string>

/** @class ModuleEndExcep ModuleEndExcep.h "ModuleEndExcep.h"
 *
 *  Specification for when the module terminates*/
class ModuleEndExcep : public std::runtime_error {
public:
   explicit ModuleEndExcep(const std::string& message = "");

   virtual ~ModuleEndExcep() noexcept = default;
};

#endif