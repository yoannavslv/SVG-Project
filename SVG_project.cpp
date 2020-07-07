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

	Utility f;
	Vector<char*> commands;

	Vector<Figures*> figures;
	

	bool exit = 1;
	int figureNumber;
	char currentFile[28];
	bool isOpen = false;

	std::cout << "Welcome to SVG file program. " << std::endl;
	std::cout << "This program will help you work with SVG files" << std::endl;
	std::cout << "The commands are : {open, close, save, saveas, help, exit, print, create, erase}" << std::endl;
	std::cout << std::endl;

	do
	{    
		std::cout << "Choose your command: \n< ";
		std::cin.getline(command, 128);
		commands = f.split(command);

		switch (f.checkTheOperation(command))
		{
			
		case 1:  //open case
			if (isOpen == true)
			{
				std::cout << "You can not open new file if there is an open file already" << std::endl;
				std::cout << std::endl;
				break;
			}
			else
			{
				strcpy_s(currentFile, strlen(f.split(command)[1]) + 1, f.split(command)[1]);
				std::cout << "You are opening " << currentFile << std::endl;
				figures = f.open(currentFile);
				f.save(figures, currentFile);
				isOpen = true;
				std::cout << std::endl;
				break;
			}
			
		case 2:  //close case

			if (isOpen == false) 
			{
				std::cout << "There is no opened file" << std::endl;
				std::cout << std::endl;
				break;
			}
			else
			{
				figures.deleteAfter(0);
				std::cout << "You are closing your file" << std::endl;
				std::cout << std::endl;
				isOpen = false;
				break;
			}

		case 3: //save case
			
			if (isOpen == false) 
			{
				std::cout << "There is no opened file" << std::endl;
				std::cout << std::endl;
				break;
			}
			else
			{
				f.save(figures, currentFile);
				std::cout << " Your file " << currentFile << " is successfully saved! " << std::endl;
				std::cout << std::endl;
				break;
			}
			
		case 4: //saveas case

			if (isOpen == false)
			{
				std::cout << "There is no opened file" << std::endl;
				std::cout << std::endl;
				break;
			}
			else
			{
				f.saveas(figures, f.split(command)[1]);
				std::cout << " Your file " << command[1] << "is successfully saved! " << std::endl;
				std::cout << std::endl;
				break;
			}
			

		case 5: //help case

			f.help();
			std::cout << std::endl;
			break;

		case 6: //exit case

			exit = 0;
			std::cout << "You are exiting the program" << std::endl;
			std::cout << std::endl;
			break;

		case 7:  //print case

			if (isOpen == false)
			{
				std::cout << "There is no opened file" << std::endl;
				std::cout << std::endl;
				break;
			}
			else
			{
				std::cout << "You are now printing your figures: " << std::endl;
				f.print(figures);
				std::cout << std::endl;
				break;
			}
			
		case 8:  //create case
		
			if (strcmp(commands[1], "circle") == 0)
			{				
				figures.push_back(new Circle (f.charToInt(commands[2]), f.charToInt(commands[3]), f.charToInt(commands[4]), commands[5]));
				std::cout << "You have created circle." << std::endl;
				std::cout << std::endl;
			}
			if (strcmp(commands[1], "ellipse") == 0)
			{				
				figures.push_back(new Ellipse (f.charToInt(commands[2]), f.charToInt(commands[3]), f.charToInt(commands[4]), f.charToInt(commands[5]), f.charToInt(commands[6]), commands[7]));
				std::cout << "You have created ellipse." << std::endl;
				std::cout << std::endl;
			}
			if (strcmp(commands[1], "rectangle") == 0)
			{
				figures.push_back(new Rectangle (f.charToInt(commands[2]), f.charToInt(commands[3]), f.charToInt(commands[4]), f.charToInt(commands[5]), commands[6]));
				std::cout << "You have created rectangle." << std::endl;
				std::cout << std::endl;
			}
			break;
			
		case 9:  //erase case

			std::cin >> figureNumber;
			if (figureNumber > figures.length())
			{
				std::cout << "Invalid figure number" << std::endl;
				break;
			}
			figures.swap(figureNumber - 1, figures.length() - 1);
			figures.deleteAfter(figures.length() - 1);
			std::cout << std::endl;
			break;
		}
		
	} while (exit);
}

