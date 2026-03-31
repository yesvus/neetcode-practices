#include <utility>
#include <vector>

class Solution {
private:
    int partition(std::vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int smallerIndex = low;

        // Move values smaller than the pivot to the left side.
        for (int i = low; i < high; i++) {
            if (nums[i] < pivot) {
                std::swap(nums[smallerIndex], nums[i]);
                smallerIndex++;
            }
        }

        std::swap(nums[smallerIndex], nums[high]);
        return smallerIndex;
    }

    void quickSortRange(std::vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int pivotIndex = partition(nums, low, high);
        quickSortRange(nums, low, pivotIndex - 1);
        quickSortRange(nums, pivotIndex + 1, high);
    }

public:
    std::vector<int> quickSort(std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        quickSortRange(nums, 0, nums.size() - 1);
        return nums;
    }
};
