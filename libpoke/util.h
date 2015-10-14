#pragma once

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <memory>

using namespace std;

template<typename T>
using raw_ptr = T*;

// Pseudo range-based iteration over enumeration types
#define enum_foreach(ENUM, VAR) for(ENUM VAR = (ENUM)std::underlying_type<ENUM>::type(0); \
									(std::underlying_type<ENUM>::type)VAR < (std::underlying_type<ENUM>::type)ENUM##::##COUNT; \
									VAR = (ENUM)(((std::underlying_type<ENUM>::type)VAR) + 1))