/*********************************************************************
** File name:  
** Author:  Michael Ross
** Date:  
** Description:  
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

using std::cout;

class Item
{
private:
	int delFlg;
	std::string itemName;
public:
	Item();
	int getDelFlg();
	std::string getItemName();
	void setDelFlg(int);
	void setItemName(std::string);
};

#endif