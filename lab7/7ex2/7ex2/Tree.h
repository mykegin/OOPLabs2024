#pragma once
#include <stdio.h>

template <class T>
class Node
{

public:
	Node** noduricopii;
	int nrcopii;
	int spatiu;
	T data;
	Node()
	{
		noduricopii = new Node * [10];
		nrcopii = 0;
		spatiu = 10;
	}
};

template <class T>
class Tree
{
	Node<T>* radacina;
public:
	Tree()
{
	radacina=nullptr;
}
	void add_node(T data, Node<T>* tata);
	Node<T>* get_node(int index, Node<T>* tata);
	void delete_node(Node<T>* sterge);
	Node<T>* find(T value, Node<T>* tata, int(*callback)(T, T));
	void insert(int index, T data, Node<T>* tata);
	void sort(Node<T>* tata, int(*callback)(T, T));
	int count(Node<T>* tata);
};


template <class T>
void updateAlocatedSize(Node<T>* tata)
{
	int newSize = tata->spatiu * 2;
	Node<T>** tmp = new Node<T>*[newSize];
	for (int i = 0; i < tata->spatiu; i++)
		tmp[i] = tata->noduricopii[i];
	delete[] tata->noduricopii;
	tata->noduricopii = tmp;
	tata->spatiu = newSize;
}


template <class T>
void Tree<T>::add_node(T data, Node<T>* tata)
{
	if (tata == nullptr)
	{
		this->radacina = new Node<T>;
		this->radacina->data = data;
		return;
	}
	if (tata->spatiu <= tata->nrcopii)
		updateAlocatedSize(tata);

	tata->noduricopii[tata->nrcopii] = new Node<T>;
	tata->noduricopii[tata->nrcopii]->data = data;
	tata->nrcopii += 1;
}

template <class T>
Node<T>* Tree<T>::get_node(int index, Node<T>* tata)
{
	if (tata == nullptr) {
		return this->radacina;
	}
	return tata->noduricopii[index];
}

template <class T>
void Tree<T>::delete_node(Node<T>* sterge)
{
	if (sterge == nullptr)
		return;

	for (int i = 0; i < sterge->nrcopii; i++)
	{
		if (sterge->noduricopii[i])
			delete_node(sterge->noduricopii[i]);
	}
	delete sterge;
}

template <class T>
Node<T>* Tree<T>::find(T value, Node<T>* tata, int(*callback)(T, T))
{
	if (tata == nullptr)
		return nullptr;
	if (callback(tata->data, value) == 0)
		return tata;
	for (int i = 0; i < tata->nrcopii; i++)
	{
		Node<T>* searchedNode = find(value, tata->noduricopii[i], callback);
		if (searchedNode != nullptr)
			return searchedNode;
	}
	return nullptr;
}

template <class T>
void Tree<T>::insert(int index, T data, Node<T>* tata)
{
	if (index < 0)
	{
		printf("Error: index can't be negative.");
		return;
	}
	if (index > tata->nrcopii)
		index = tata->nrcopii;
	while (index >= tata->spatiu) {
		updateAlocatedSize(tata);
	}

	if (tata->noduricopii[index] == nullptr) {
		tata->noduricopii[index] = new Node<T>;
		tata->noduricopii[index]->data = data;
		tata->nrcopii += 1;
		return;
	}

	if (tata->nrcopii >= tata->spatiu) {
		updateAlocatedSize(tata);
	}

	for (int i = tata->spatiu; i > index; --i)
	{
		tata->noduricopii[i] = tata->noduricopii[i - 1];
	}

	tata->noduricopii[index] = new Node<T>;
	tata->noduricopii[index]->data = data;
	tata->nrcopii += 1;
}

template <class T>
void Tree<T>::sort(Node<T>* tata, int(*callback)(T, T))
{
	for (int i = 0; i < tata->nrcopii - 1; i++) {
		for (int j = 0; j < tata->nrcopii; j++)
		{
			if ((callback != nullptr && callback(tata->noduricopii[i]->data, tata->noduricopii[j]->data))
				|| (callback == nullptr && tata->noduricopii[i]->data > tata->noduricopii[j]->data))
			{
				Node<T>* tmp = tata->noduricopii[i];
				tata->noduricopii[i] = tata->noduricopii[j];
				tata->noduricopii[j] = tata;
			}
		}
	}
}

template <class T>
int Tree<T>::count(Node<T>* tata)
{
	if (tata == nullptr)
		tata = this->radacina;
	int cnt = 0;
	for (int i = 0; i < tata->nrcopii; i++)
	{
		if (tata->noduricopii[i] != nullptr)
			cnt += 1 + count(tata->noduricopii[i]);
	}
	return cnt;
}
