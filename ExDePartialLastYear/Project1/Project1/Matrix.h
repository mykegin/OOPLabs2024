#pragma once
class Matrix
{
	int** mat;
	int l,h;

public:
	Matrix(int length, int height);
	~Matrix();

	int& operator() (int x, int y);
	int operator[] (const char* x);
	bool operator== (Matrix& x);

	void print();
	bool is_identity_matrix();
	bool is_square_matrix();
	void fill(int x);
};

