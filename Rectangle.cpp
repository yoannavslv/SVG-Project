#include "Rectangle.h"

void Rectangle::copy(const Rectangle& another)
{
	this->setX(another.x);
	this->setY(another.y);
	this->setWidth(another.width);
	this->setHeight(another.height);
	this->setColor(another.color);
}

void Rectangle::destroy()
{
	delete[] this->color;
}

Rectangle::Rectangle()
{
	this->setX(0);
	this->setY(0);
	this->setWidth(0);
	this->setHeight(0);
	this->setColor("Default");
}

Rectangle::Rectangle(size_t newX, size_t newY, size_t newWidth, size_t newHeight, const char* newColor) : color(nullptr)
{

	this->setX(newX);
	this->setY(newY);
	this->setWidth(newWidth);
	this->setHeight(newHeight);
	this->setColor(newColor);
}

Rectangle::Rectangle(const Rectangle& another)
{
	copy(another);
}

Rectangle& Rectangle::operator=(const Rectangle& another)
{
	if (this != &another)
	{
		copy(another);
	}
	return *this;
}

Rectangle::~Rectangle()
{
	destroy();
}

void Rectangle::setX(size_t newX)
{
	this->x = newX;
}

size_t Rectangle::getX() const
{
	return this->x;
}

void Rectangle::setY(size_t newY)
{
	this->y = newY;
}

size_t Rectangle::getY() const
{
	return this->y;
}

void Rectangle::setWidth(size_t newWidth)
{
	this->width = newWidth;
}

size_t Rectangle::getWidth() const
{
	return this->width;
}

void Rectangle::setHeight(size_t newHeight)
{
	this->height = newHeight;
}

size_t Rectangle::getHeight() const
{
	return this->height;
}

void Rectangle::setColor(const char* newColor)
{
	if (newColor != nullptr)
	{
		delete[] this->color;
		this->color = new char[strlen(newColor) + 1];
		strcpy_s(this->color, strlen(newColor) + 1, newColor);
	}
}

const char* Rectangle::getColor() const
{
	return this->color;
}

void Rectangle::print()
{
	std::cout << "rectangle " << this->x << " " << this->y << " " << this->width << " "
		<< this->height << " " << this->color << std::endl;
}

void Rectangle::output(std::ostream& stream)
{
	stream << "<rect x=\"" << this->getX() << "\" y=\"" << this->getY() << "\" width=\"" << this->getWidth() << "\" ";
	stream << "height=\"" << this->getHeight() << "\" fill=\"" << this->getColor() << "\" \>" << std::endl;
}



