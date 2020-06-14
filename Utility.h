#pragma once
#include"Vector.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"

class Utility
{
public:
	size_t numberOfSymbols(char* text, char symbol); //returns the number of how many times a symbol is in a char 
	char* substring(char* text, int firstPosition, int secondPosition); //returns a part of char between two or more given indexes
	size_t index(char* text, char symbol); //returns the first inedx of symbol in char
	size_t theLastIndex(char* text, char symbol); //returns the last index of symbol in char
	Vector<char*> split(char* text); //split char by space
	size_t checkTheOperation(char* text); //check if the given command is valid
	void print(Vector<Figures*> figures); //function that prints the figures from the vector
	void help(); //function which cout help dialog and gives information about every possible command
	void save(Vector<Figures*>& figures, const char* namef); //save command
	void saveas(Vector<Figures*>& figures, const char* nameofFile); //save as command
	Vector<Figures*> open(const char* file); //command open
	int charToInt(char* figure); //char is converting to int

	//the finctions numberOfSymbols, substring, index, theLastIndex, checkTheOperation, charToInt are taken from my colegue Veselin Todorov
};

