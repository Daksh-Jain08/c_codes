#include<iostream>

using namespace std;

class Heap{
  private:
    int *arr;
  public:
    Heap(){};
    Heap(int *arr, int n);
    int* get_arr(){return arr;}
    void swap(int *a, int *b);
    void insert(int value);
    int deleteEle(int index);
    void heapSort(int* a, int n);
    void heapify(int *a, int n);
    void heapReorder(int *a, int index, int n);
};
