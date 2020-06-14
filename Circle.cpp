#include "Circle.h"
#include <cstring>

void Circle::copy(const Circle& other)
{
	this->setCX(other.cx);
	this->setCY(other.cy);
	this->setR(other.r);
	this->setColor(other.color);
}

void Circle::destroy()
{
	delete[] this->color;
}

Circle::Circle() : color(nullptr)
{
	this->setCX(0);
	this->setCY(0);
	this->setR(0);
	this->setColor("Default");
}

Circle::Circle(double newCX, double newCY, double newR, const char* newColor)
{
	this->setCX(newCX);
	this->setCY(newCY);
	this->setR(newR);
	this->setColor(newColor);
}

Circle::Circle(const Circle& other)
{
	copy(other);
}

Circle::~Circle()
{
	destroy();
}

void Circle::setCX(double newCX)
{
	this->cx = newCX;
}

double Circle::getCX() const
{
	return this->cx;
}

void Circle::setCY(double newCY)
{
	this->cy = newCY;
}

double Circle::getCY() const
{
	return this->cy;
}

void Circle::setR(double newR)
{
	this->r = newR;
}

double Circle::getR() const
{
	return this->r;
}

void Circle::setColor(const char* newColor)
{
	if (newColor != nullptr)
	{
		delete[] this->color;
		this->color = new char[strlen(newColor) + 1];
		strcpy_s(this->color, strlen(newColor) + 1, newColor);
	}
}

const char* Circle::getColor() const
{
	return this->color;
}

void Circle::print()
{
	std::cout << "circle " << this->cx << " " << this->cy << " "
		<< this->r << " " << this->color << std::endl;
}

void Circle::output(std::ostream& stream)
{
	stream << "<circle cx=\"" << getCX() << "\" cy=\"" << getCY() << "\" r=\"" << getR() << "\"";
	stream << " fill=\"" << getColor() << "\" />\n";
}

