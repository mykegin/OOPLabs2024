#pragma once
class Sorti
{
    // add data members
    int* lista;
    int nr;
public:
    // add constuctors
    Sorti(int nrelem, int mini, int maxi);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};