/*********************************************************************
** File name:  checkInputValue.hpp
** Author:  Michael Ross
** Date:  1/29/17
** Description:  A validation function that ensures safe user inputs 
		for	integer based menu functions.
*********************************************************************/

#ifndef VALIDATEINPUT_HPP
#define VALIDATEINPUT_HPP

#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <iostream>
#include <string>

using std::cout;

bool checkInputValue(std::string,int&);
bool checkInputValue2(std::string, int&);

#endif