#pragma once
#include <iostream>

template <typename T>
class Vector
{
private:
	T* object;
	size_t size;

	void copy(const Vector& another);
	void destroy();

public:
	Vector();
	Vector(const Vector& another);
	Vector& operator=(const Vector& another);
	~Vector();

	Vector<T> operator+(const Vector<T>& another) const;
	Vector<T>& operator+=(const Vector<T>& another);
	Vector<T>& deleteAfter(size_t number);
	T& operator[](size_t j);
	void swap(size_t first, size_t second);
	void push(const T& another);
	void push_back(const T& another);
	size_t length();

	friend std::ostream& operator<<(std::ostream& out, Vector<T> vector)
	{
		for (size_t i = 0; i < vector.length(); i++)
		{
			out << vector[i] << std::endl;
		}
		return out;
	}
};

template<typename T>
void Vector<T>::copy(const Vector<T>& another)
{
	this->object = new T[another.size];
	for (size_t i = 0; i < another.size; i++)
	{
		this->object[i] = another.object[i];
	}
	this->size = another.size;
}

template<typename T>
void Vector<T>::destroy()
{
	delete[] this->object;
}

template<typename T>
Vector<T>::Vector()
{
	this->object = nullptr;
	this->size = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& another)
{
	copy(another);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& another)
{
	if (this != &another)
	{
		destroy();
		copy(another);
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	destroy();
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& another) const
{
	Vector<T> newResult;
	newResult.size = this->size + another.size;
	newResult.object = new T[newResult.size];
	for (size_t i = 0; i < this->size; i++)
	{
		newResult.object[i] = this->object[i];
	}
	for (size_t i = 0; i < another.size; i++)
	{
		newResult.object[this->size + i] = another.object[i];
	}

	return newResult;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& another)
{
	T* newBuffer = new T[this->size + another.size];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->object[i];
	}
	for (size_t i = 0; i < another.size; i++)
	{
		newBuffer[this->size + i] = another.object[i];
	}
	destroy();
	this->size += another.size;
	this->object = newBuffer;
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::deleteAfter(size_t number)
{
	this->size = number;
	T* biggerBuffer = new T[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		biggerBuffer[i] = this->object[i];
	}
	destroy();
	this->object = biggerBuffer;
	return *this;
}

template<typename T>
T& Vector<T>::operator[](size_t j)
{
	return this->object[j];
}

template<typename T>
void Vector<T>::swap(size_t first, size_t second)
{
	T current = this->object[first];
	this->object[first] = this->object[second];
	this->object[second] = current;
}

template<typename T>
void Vector<T>::push(const T& another)
{
	T* newBuffer = new T[this->size + 1];
	newBuffer[0] = another;
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i + 1] = this->object[i];
	}
	destroy();
	this->object = newBuffer;
	size++;
}

template<typename T>
void Vector<T>::push_back(const T& another)
{
	T* newBuffer = new T[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->object[i];
	}
	newBuffer[this->size] = another;
	destroy();
	this->object = newBuffer;
	size++;
}

template<typename T>
size_t Vector<T>::length()
{
	return this->size;
}

