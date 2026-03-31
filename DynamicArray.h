#pragma once
#include <iostream>

class DynamicArray {
private:
  int *arr;
  int length;
  int capacity;

public:
  DynamicArray(int capacity);
  int get(int i);
  void set(int i, int n);
  void pushback(int n);
  int popback();
  void resize();
  int getSize();
  int getCapacity();
  ~DynamicArray();
};
