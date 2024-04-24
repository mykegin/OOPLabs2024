#include "Matrix.h"
#include <stdio.h>

Matrix::Matrix(int length, int height)
{
	this->l = length;
	this->h = height;

	this->mat = new int* [height];
	for (int i = 0; i < height; i++)
		this->mat[i] = new int[length];
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->h; i++)
		delete[] this->mat[i];
	delete[] this->mat;
}

int& Matrix::operator()(int x, int y)
{
	return this->mat[y][x];
}

int Matrix::operator[](const char* x)
{
	if (x == "width")
	{
		return this->l;
	}

	if (x == "height")
	{
		return this->h;
	}

	if (x == "size")
	{
		return this->l * this->h * sizeof(int);
	}

	return 0;
}

bool Matrix::operator==(Matrix& x)
{
	if (this->l != x.l || this->h != x.h)
		return 0;
	int i, j;

	for (i = 0; i < this->h; i++)
	{
		for (j = 0; j < this->l; j++)
			if (this->mat[i][j] != x.mat[i][j])
				return 0;
	}
	return 1;
}

void Matrix::print()
{
	int i, j;
	for (i = 0; i < this->h; i++)
	{
		for (j = 0; j < this->l; j++)
			printf("%d ", this->mat[i][j]);
		printf("\n");
	}
}

bool Matrix::is_identity_matrix()
{
	if (this->h != this->l)
		return false;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (this->mat[i][j] != (i == j))
				return false;
		}
	}

	return true;
}

bool Matrix::is_square_matrix()
{
	if (this->l == this->h)
		return true;
	return false;
}

void Matrix::fill(int x)
{
	int i, j;
	for (i = 0; i < this->h; i++)
	{
		for (j = 0; j < this->l; j++)
			this->mat[i][j] = x;
	}
}
