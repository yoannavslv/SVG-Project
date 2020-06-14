#include "Ellipse.h"

void Ellipse::copy(const Ellipse& other)
{
	this->setCX(other.cx);
	this->setCY(other.cy);
	this->setRX(other.rx);
	this->setRY(other.ry);
	this->setStroke_Width(other.stroke_width);
	this->setColor(other.color);
}

void Ellipse::destroy()
{
	delete[] this->color;
}

Ellipse::Ellipse() : color(nullptr)
{
	this->setCX(0);
	this->setCY(0);
	this->setRX(0);
	this->setRY(0);
	this->setStroke_Width(0);
	this->setColor("None");
}

Ellipse::Ellipse(int newCX, int newCY, int newRX, int newRY, int newStroke_Width, const char* newColor) : color(nullptr)
{
	this->setCX(newCX);
	this->setCY(newCY);
	this->setRX(newRX);
	this->setRY(newRY);
	this->setStroke_Width(newStroke_Width);
	this->setColor(newColor);
}

Ellipse::Ellipse(const Ellipse& other)
{
	copy(other);
}

Ellipse& Ellipse::operator=(const Ellipse& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

Ellipse::~Ellipse()
{
	destroy();
}

void Ellipse::setCX(int newCX)
{
	this->cx = newCX;
}

int Ellipse::getCX() const
{
	return this->cx;
}

void Ellipse::setCY(int newCY)
{
	this->cy = newCY;
}

int Ellipse::getCY() const
{
	return this->cy;
}

void Ellipse::setRX(int newRX)
{
	this->rx = newRX;
}

int Ellipse::getRX() const
{
	return this->rx;
}

void Ellipse::setRY(int newRY)
{
	this->ry = newRY;
}

int Ellipse::getRY() const
{
	return this->ry;
}

void Ellipse::setStroke_Width(int newStroke_Width)
{
	this->stroke_width = newStroke_Width;
}

int Ellipse::getStroke_Width() const
{
	return this->stroke_width;
}

void Ellipse::setColor(const char* newColor)
{
	if (newColor != nullptr)
	{
		delete[] this->color;
		this->color = new char[strlen(newColor) + 1];
		strcpy_s(this->color, strlen(newColor) + 1, newColor);
	}
}

const char* Ellipse::getColor() const
{
	return this->color;
}

void Ellipse::print()
{
	std::cout << "ellipse " << this->cx << " " << this->cy << " " << this->rx << " " << this->ry << " "
		<< this->stroke_width << " " << this->color << std::endl;
}

void Ellipse::output(std::ostream& stream)
{
	stream << "<ellipse cx=\"" << this->getCX() << "\" cy=\"" << this->getCY() << "\" rx=\"" << this->getRX() << "\"";
	stream << " ry=\"" << this->getRY() << "\"" << " stroke-width=\"" << this->getStroke_Width() << "\""
		<< " fill=\"" << this->getColor() << "\" />\n";
}

