#pragma once
#include<iostream>
class Figures
{
public:
	virtual void print() = 0; //prints a figure in the console
	virtual void output(std::ostream& stream) = 0; //outputs figures into the file
};