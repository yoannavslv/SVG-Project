#pragma once
#include"Vector.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"

class Utility
{
public:
	static size_t numberOfSymbols(char* text, char symbol); //returns the number of how many times a symbol is in a char 
	static char* substring(char* text, int firstPosition, int secondPosition); //returns a part of char between two or more given indexes
	static size_t index(char* text, char symbol); //returns the first inedx of symbol in char
	static size_t theLastIndex(char* text, char symbol); //returns the last index of symbol in char
	static Vector<char*> split(char* text); //split char by space
	static size_t checkTheOperation(char* text); //check if the given command is valid
	static void print(Vector<Figures*>& figures); //function that prints the figures from the vector
	static void help(); //function which cout help dialog and gives information about every possible command
	static void save(Vector<Figures*>& figures, const char* namef); //save command
	static void saveas(Vector<Figures*>& figures, const char* nameofFile); //save as command
	static Vector<Figures*> open(const char* file); //command open
	static int charToInt(char* figure); //char is converting to int

	//the finctions numberOfSymbols, substring, index, theLastIndex, checkTheOperation, charToInt are taken from my colegue Veselin Todorov
};

