#pragma once
#include"Figures.h"
#include <iostream>
class Circle : public Figures
{
private:
	//data 
	double cx, cy, r;
	char* color;

	void copy(const Circle& other);
	void destroy();

public:
	//constructors, setters and getters
	Circle();
	Circle(double newCX, double newCY, double newR, const char* newColor);
	Circle(const Circle& other);
	~Circle();

	void setCX(double newCX);
	double getCX() const;

	void setCY(double newCY);
	double getCY() const;

	void setR(double newR);
	double getR() const;

	void setColor(const char* newColor);
	const char* getColor() const;

	//the methods from class Figures which is inherited
	void print();
	void output(std::ostream& stream);
};


