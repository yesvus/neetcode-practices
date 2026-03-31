#include "DynamicArray.h"

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