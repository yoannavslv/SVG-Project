#include <iostream>
#include "Utility.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Figures.h"
#include "Rectangle.h"
#include "Vector.h"

int main()
{
    char command[128];

	Utility functions;
	Vector<char*> commands;

	Vector<Figures*> figures;
	

	bool exit = 1;
	char create[16];
	int figureNumber;
	char currentFile[28];
	bool isOpen = false;

	std::cout << "Welcome to SVG file program. " << std::endl;
	std::cout << "Choose your command: {open , close, save, saveas, help, exit, print, create, erase}" << std::endl;

	do
	{    
		//std::cout << " < ";
		std::cin.getline(command, 128);
		commands = functions.split(command);

		switch (functions.checkTheOperation(command))
		{
			
		case 1:  //open case
		
				strcpy_s(currentFile, strlen(functions.split(command)[1]) + 1, functions.split(command)[1]);
				std::cout << "You are opening " << currentFile << std::endl;
				functions.open(currentFile); 
				
			break;
		case 2:  //close case

			figures.deleteAfter(0);
		    std::cout << "You are closing you file" << std::endl;	
			break;

		case 3: //save case
			
			functions.save(figures, currentFile);
			break;

		case 4: //saveas case

			functions.saveas(figures, functions.split(command)[1]);
			break;

		case 5: //help case

			functions.help(); 
			break;

		case 6: //exit case

			exit = 0;
			std::cout << "You are exiting the program" << std::endl;
			break;

			
		case 7:  //print case

			std::cout << "You are now printing your figures: " << std::endl;
			functions.print(figures);	
			break;

		case 8:  //create case
		
			if (strcmp(commands[1], "circle") == 0)
			{
				Circle newCircle(functions.charToInt(commands[2]), functions.charToInt(commands[3]), functions.charToInt(commands[4]), commands[5]);
				std::cout << "You have created circle." << std::endl;
				break;
				figures.push_back(&newCircle);
			}
			if (strcmp(commands[1], "ellipse") == 0)
			{
				Ellipse newEllipse(functions.charToInt(commands[2]), functions.charToInt(commands[3]), functions.charToInt(commands[4]), functions.charToInt(commands[5]), functions.charToInt(commands[6]), commands[7]);
				std::cout << "You have created circle." << std::endl;
				figures.push_back(&newEllipse);
			}
			if (strcmp(commands[1], "rectangle") == 0)
			{
				Rectangle newRectangle(functions.charToInt(commands[2]), functions.charToInt(commands[3]), functions.charToInt(commands[4]), functions.charToInt(commands[5]), commands[6]);
				std::cout << "You have created circle." << std::endl;
				figures.push_back(&newRectangle);
			}
			
			
		case 9:  //erase case

			std::cin >> figureNumber;
			if (figureNumber > figures.length())
			{
				std::cout << "Invalid figure number" << std::endl;
				break;
			}
			figures.swap(figureNumber - 1, figures.length() - 1);
			figures.deleteAfter(figures.length() - 1);
			break;
		}
		
	} while (exit);
}

