#include "Canvas.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

Canvas::Canvas(int width, int height)
{
	this->matrix = new char* [height];
	for (int i = 0; i < height; ++i)
	{
		this->matrix[i] = new char[width];
		for (int j = 0; j < width; j++)
			this->matrix[i][j] = ' ';
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			///printf("%c", this->matrix[i][j]);
		printf("0");
		printf("\n");
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
		{
			this->matrix[i][left] = ch;
			this->matrix[i][right] = ch;
			this->matrix[top][j] = ch;
			this->matrix[bottom][j] = ch;
		}

}