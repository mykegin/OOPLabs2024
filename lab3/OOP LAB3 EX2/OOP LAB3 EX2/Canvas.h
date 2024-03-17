#pragma once
class Canvas
{
    int rows, cols;
    char** matrix;

public:


    Canvas(int width, int height);
    void DrawCircle(int x, int y, int ray, char ch);///done
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);///done
    void FillRect(int left, int top, int right, int bottom, char ch);///done
    void SetPoint(int x, int y, char ch);///done
    void DrawLine(int x1, int y1, int x2, int y2, char ch); ///cone
    void Print(); // shows what was printed    done
    void Clear(); // clears the canvas   done
};