#include "Utility.h"
#include <fstream>
#include <iostream>

char command[9][7] = { "open" , "close", "save", "saveas", "help", "exit", "print",
								"create", "erase" };

size_t Utility::numberOfSymbols(char* text, char symbol)
{
	size_t counter = 0;
	size_t lenght = strlen(text);
	for (size_t i = 0; i < lenght; i++)
	{
		if (text[i] == symbol)
		{
			counter++;
		}
	}
	return counter;
}

char* Utility::substring(char* text, int firstPosition, int secondPosition)
{
	size_t lenght = strlen(text);
	char* substring = new char[lenght - firstPosition + 1];
	for (size_t i = 0; i < secondPosition - firstPosition; i++)
	{
		substring[i] = text[i + firstPosition];
	}
	substring[secondPosition - firstPosition] = 0;
	return substring;
}

size_t Utility::index(char* text, char symbol)
{
	size_t lenght = strlen(text);
	for (size_t i = 0; i < lenght; i++)
	{
		if (text[i] == symbol)
		{
			return i;
		}
	}
}

size_t Utility::theLastIndex(char* text, char symbol)
{
	int lenght = strlen(text);
	for (int i = lenght; i >= 0; i--)
	{
		if (text[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}

Vector<char*> Utility::split(char* text)
{
	Vector<char*> newSpace;
	while (numberOfSymbols(text, ' '))
	{
		newSpace.push_back(substring(text, 0, index(text, ' ')));
		text = substring(text, index(text, ' ') + 1, strlen(text) + 1);
	}
	newSpace.push_back(text);
	return newSpace;
}

size_t Utility::checkTheOperation(char* text)
{
	Vector<char*> part = split(text);
	for (size_t i = 0; i < 9; i++)
	{
		if (strcmp(part[0], command[i]) == 0)
		{
			return i + 1;
		}
	}
	return -1;
}

void Utility::print(Vector<Figures*>& figures)
{
	for (size_t i = 0; i < figures.length(); i++)
	{
		figures[i]->print();
	}
}

void Utility::help()
{
	std::cout << "The following commands are supported: " << std::endl;
	std::cout << "open <file>    opens <file>" << std::endl;
	std::cout << "close            closes currently opened file" << std::endl;
	std::cout << "save            saves the currently open file" << std::endl;
	std::cout << "saveas <file>    saves the currently open file in <file>" << std::endl;
	std::cout << "help            prints this information" << std::endl;
	std::cout << "exit            exists the program" << std::endl;
	std::cout << "print           prints all figures" << std::endl;
	std::cout << "create         creates figure" << std::endl;
	std::cout << "erase <n>      deletes the <n>th figure" << std::endl;
}

void Utility::save(Vector<Figures*>& figures, const char* namef)
{
	std::ofstream file;
	file.open(namef);

	file << "< ? xml version = \"1.0\" standalone = \"no\" ? >" << std::endl
		<< "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl
		<< "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl
		<< "<svg>" << std::endl;

	for (size_t i = 0; i < figures.length(); i++)
	{
		figures[i]->output(file);
	}

	file << "</svg>" << std::endl;
	file.close();
}

void Utility::saveas(Vector<Figures*>& figures, const char* nameofFile)
{
	std::ofstream file;
	file.open(nameofFile);

	file << "< ? xml version = \"1.0\" standalone = \"no\" ? >" << std::endl
		<< "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl
		<< "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl
		<< "<svg>" << std::endl;

	for (size_t i = 0; i < figures.length(); i++)
	{
		figures[i]->output(file);
	}

	file << "</svg>" << std::endl;
	file.close();
}

Vector<Figures*> Utility::open(const char* file)
{
	char sentence[128];
	std::ifstream newFile;
	newFile.open(file);
	Vector<Figures*> figures; 

	while (!newFile.eof())
	{

		newFile.get();
		newFile.getline(sentence, 128); 
		if (strcmp(sentence, "") == 0) 
			break; 

		Vector<char*> smb = split(sentence);

		if (strcmp(smb[0], "rect") == 0)
		{
			for (size_t i = 1; i <= 5; i++)
			{
				smb[i] = substring(smb[i], index(smb[i], '\"') + 1, theLastIndex(smb[i], '\"'));
				
			}
			figures.push_back(new Rectangle(charToInt(smb[1]), charToInt(smb[2]), charToInt(smb[3]), charToInt(smb[4]), smb[5]));
			
		}
		if (strcmp(smb[0], "circle") == 0)
		{
			for (size_t i = 1; i <= 4; i++)
			{
				smb[i] = substring(smb[i], index(smb[i], '\"') + 1, theLastIndex(smb[i], '\"'));
			}
			figures.push_back(new Circle(charToInt(smb[1]), charToInt(smb[2]), charToInt(smb[3]), smb[4]));

		}
		if (strcmp(smb[0], "ellipse") == 0)
		{
			for (size_t i = 1; i <= 6; i++)
			{
				smb[i] = substring(smb[i], index(smb[i], '\"') + 1, theLastIndex(smb[i], '\"'));
			}

			figures.push_back(new Ellipse(charToInt(smb[1]), charToInt(smb[2]), charToInt(smb[3]), charToInt(smb[4]), charToInt(smb[5]), smb[6]));
		}
	}

	newFile.close();
	return figures;
}

int Utility::charToInt(char* figure)
{
	int sum = 0;
	bool negativeNum = figure[0] == '-';
	if (negativeNum)
	{
		for (size_t i = 1; i < strlen(figure); i++)
		{
			sum += (figure[i] - '0');
			sum *= 10;
		}
	}
	else
	{
		for (size_t i = 0; i < strlen(figure); i++)
		{
			sum += (figure[i] - '0');
			sum *= 10;
		}
	}

	if (negativeNum)
	{
		return (sum / 10) * -1;
	}
	return sum / 10;
}
