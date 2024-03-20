#pragma once
class Sort
{
    // add data members
    int* lista;
    int vectorsort3[10] = { 7,1,8,9,2,3,5,4,6,10 };
    char* stringul;
    int nr;
public:
    // add constuctors
    Sort(int nrelem, int mini, int maxi);
    Sort();
    Sort(int vectoras[], int nrelem);
    Sort(int count, ...);
    Sort(const char* c);
    void InsertSort(bool ascendent = false);///done
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);///done
    void Print();///done
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};