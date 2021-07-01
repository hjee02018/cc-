#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
private:
	string name;
public:
	void setName(string name);
	string getName();
};
