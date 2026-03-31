#include "DynamicArray.h"

DynamicArray::DynamicArray(int capacity) {
  this->capacity = capacity;
  this->length = 0;
  this->arr = new int[capacity];
}

int DynamicArray::get(int i) { return arr[i]; }

void DynamicArray::set(int i, int n) { arr[i] = n; }

void DynamicArray::pushback(int n) {
  if (length == capacity) {
    resize();
  }
  arr[length] = n;
  length++;
}

int DynamicArray::popback() {
  length--;
  return arr[length];
}

void DynamicArray::resize() {
  capacity = capacity * 2;
  int *newArr = new int[capacity];
  for (int i = 0; i < length; i++) {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
}

int DynamicArray::getSize() { return length; }

int DynamicArray::getCapacity() { return capacity; }

DynamicArray::~DynamicArray() { delete[] arr; }

#ifdef DYNAMIC_ARRAY_DEMO
int main() {
  DynamicArray arr(2); // Create a dynamic array with initial capacity of 2

  arr.pushback(10); // Add elements to the array
  arr.pushback(20);
  arr.pushback(30); // This will trigger a resize

  for (int i = 0; i < arr.getSize(); i++) {
    std::cout << arr.get(i) << " "; // Print elements in the array
  }
  std::cout << std::endl;

  std::cout << "Size: " << arr.getSize() << std::endl; // Print current size
  std::cout << "Capacity: " << arr.getCapacity()
            << std::endl; // Print current capacity

  return 0;
}
#endif
