#pragma once
class Canvas
{
    int rows = 100, cols = 100;
    char** matrix;

public:


    Canvas(int width, int height)
    {
        this->matrix = new char* [height];
        for (int i = 0; i < height; ++i)
        {
            this->matrix[i] = new char[width];
            for (int j = 0; j < width; j++)
                this->matrix[i][j] = ' ';
        }
    }
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};

