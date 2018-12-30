/*********************************************************************
** File name:  checkInputValue.cpp
** Author:  Michael Ross
** Date:  2/12/17
** Description:  A validation function that ensures safe user inputs
		for	integer based menu functions.
*********************************************************************/

#include "checkInputValue.hpp"

/*********************************************************************
*		checkInputValue - validates integer input
*********************************************************************/
bool checkInputValue(std::string input, int& convertedValue)
{
	char* endPtr;
	long userResponse = strtol(input.c_str(), &endPtr, 10);

	// Check if the input is an integer
	if (*endPtr != '\0')
	{
		cout << "Invalid Repsonse - invalid integer. ";
		return false;
	}

	// Check if number is too large
	else if (userResponse > INT_MAX)
	{
		cout << "Invalid Response - out of bounds. \n";
		return false;
	}
	else
	{
		convertedValue = static_cast<int>(userResponse);
		return true;
	}
}