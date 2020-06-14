#pragma once
#include <iostream>
#include"Figures.h"
class Ellipse : public Figures
{
private:
	//data
	int cx, cy, rx, ry, stroke_width;
	char* color;

	void copy(const Ellipse& other);
	void destroy();

public:
	//constructors, setters and getters
	Ellipse();
	Ellipse(int newCX, int newCY, int newRX, int newRY, int newStroke_Width, const char* newColor);
	Ellipse(const Ellipse& other);
	Ellipse& operator=(const Ellipse& other);
	~Ellipse();

	void setCX(int newCX);
	int getCX() const;

	void setCY(int newCY);
	int getCY() const;

	void setRX(int newRX);
	int getRX() const;

	void setRY(int newRY);
	int getRY() const;

	void setStroke_Width(int newStroke_Width);
	int getStroke_Width() const;

	void setColor(const char* newColor);
	const char* getColor() const;

	//the methods from class Figures which is inherited
	void print();
	void output(std::ostream& stream);
};