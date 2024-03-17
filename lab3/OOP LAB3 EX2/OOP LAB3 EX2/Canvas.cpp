#include "Canvas.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

Canvas::Canvas(int width, int height)
{
	this->cols = width;
	this->rows = height;
	this->matrix = new char* [height];
	for (int i = 0; i < height; ++i)
	{
		this->matrix[i] = new char[width];
		for (int j = 0; j < width; j++)
			this->matrix[i][j] = ' ';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->matrix[i][j] = ' ';
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1; ///daca x1<x2 atunci sx=1 altfel sx=-1
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	int err2;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		err2 = 2 * err;
		if (err2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			printf("%c ", this->matrix[i][j]);
		printf("\n");
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	SetPoint(left, top, ch);
	SetPoint(left, bottom, ch);
	SetPoint(right, top, ch);
	SetPoint(right, bottom, ch);
	DrawLine(left, top, right, top, ch);
	DrawLine(left, bottom, right, bottom, ch);
	DrawLine(left, top, left, bottom, ch);
	DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			SetPoint(i, j, ch);
}