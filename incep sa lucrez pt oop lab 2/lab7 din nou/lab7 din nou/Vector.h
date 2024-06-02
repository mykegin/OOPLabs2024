#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
template <class T>
class Vector
{
private:
	T* v;
	int size;
public:
	Vector();
	~Vector();
	Vector(T& g);
	Vector(T&& g);
	T operator[](int index);
	void insert(int index, T elem);
	void remove(int index);
	void sort();
	void print();
};

template<class T>
inline Vector<T>::Vector()
{
	this->size = 0;
	this->v = new T[100];
	int i;
	for (i = 0; i < 100; i++)
		this->v[i] = 0;
}

template<class T>
inline Vector<T>::~Vector()
{
	this->size = 0;
	delete[] this->v;
}

template<class T>
inline Vector<T>::Vector(T& g)
{
	this->size = g.size;
	int i;
	this->v = new T[100];
	for (i = 0; i < this->size; i++)
		this->v[i] = g.v[i];
}

template<class T>
inline Vector<T>::Vector(T&& g)
{
	this->v = g.v;
	this->size = g.size;
	g.v = nullptr;
	g.size = 0;
}

template<class T>
T Vector<T>::operator[](int index)
{
	return this->v[index];
}

template<class T>
inline void Vector<T>::insert(int index, T elem)
{
	this->v[index] = elem;
	if (index > this->size)
		this->size = index;
	this->size++;
}

template<class T>
inline void Vector<T>::remove(int index)
{
	int i = 0;
	for (i = index; i < size; i++)
		this->v[i] = this->v[i + 1];
	this->size--;
}

template<class T>
inline void Vector<T>::sort()
{
}

template<class T>
inline void Vector<T>::print()
{
	int i;
	for (i = 0; i < this->size; i++)
		cout << this->v[i];
}
