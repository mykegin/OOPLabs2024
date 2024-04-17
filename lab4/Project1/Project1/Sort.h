#pragma once
class Sort
{
    // add data members

    int* vec;
    int count;

public:
    // add constuctors

    Sort(int mini, int maxi, int nrelem);
    Sort();
    Sort(int nrelem, int v[]);
    Sort(int nrelem, ...);
    Sort(char* nr);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};