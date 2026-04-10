#include <utility>
#include <vector>

/*
Heap Sort Exercise

Goal:
- Sort the input array in ascending order using heap sort.

Prerequisites:
- Understand how array indices map to a binary tree
- Know how to swap two values in C++
- Be comfortable with `for` loops and `if` statements
- Know the difference between leaf nodes and non-leaf nodes
- Understand the max-heap property:
  each parent must be greater than or equal to its children

What to practice:
- Building a max heap
- Restoring the heap with heapify
- Moving the largest value to the end on each pass

Suggested steps:
1. Finish `heapify` so the subtree rooted at `rootIndex` satisfies the max-heap rule.
2. Build a max heap from the unsorted array.
3. Repeatedly swap the first element with the last unsorted element.
4. Heapify the reduced heap after each swap.

Example:
- Input:  [4, 10, 3, 5, 1]
- Output: [1, 3, 4, 5, 10]

Questions to check yourself:
- Why does heap construction start from `(n / 2) - 1`?
- Why do we use a max heap for ascending order?
- What is the time complexity of heap sort?
*/

class Solution {
private:
    void heapify(std::vector<int>& nums, int heapSize, int rootIndex) {
        int largest = rootIndex;
        int leftChild = (2 * rootIndex) + 1;
        int rightChild = (2 * rootIndex) + 2;

        // TODO:
        // Compare root with left child and update `largest` when needed.

        // TODO:
        // Compare current `largest` with right child and update it when needed.

        // TODO:
        // If the root is not the largest value, swap and continue heapifying.
    }

public:
    std::vector<int> heapSort(std::vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return nums;
        }

        // TODO:
        // Build a max heap by heapifying all non-leaf nodes from right to left.

        // TODO:
        // Repeatedly move the largest element to the end of the array,
        // shrink the heap, and restore the heap property.

        return nums;
    }
};
