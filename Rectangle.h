#pragma once
#include"Figures.h"
#include <iostream>

class Rectangle : public Figures
{
private:
	//data
	size_t x, y, width, height;
	char* color;

	void copy(const Rectangle& another);
	void destroy();

public:
	//constructors, setters and getters
	Rectangle();
	Rectangle(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const char* newColor);
	Rectangle(const Rectangle& another);
	Rectangle& operator=(const Rectangle& another);
	~Rectangle();

	void setX(size_t newX);
	size_t getX() const;

	void setY(size_t newY);
	size_t getY() const;

	void setWidth(size_t newWidth);
	size_t getWidth() const;

	void setHeight(size_t newHeight);
	size_t getHeight() const;

	void setColor(const char* newColor);
	const char* getColor() const;

	//the methods from class Figures which is inherited
	void print();
	void output(std::ostream& stream);
};


