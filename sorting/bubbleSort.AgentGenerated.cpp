#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> bubbleSort(std::vector<int>& nums) {
        int n = nums.size();

        // After each pass, the largest remaining element bubbles to the end.
        for (int end = n - 1; end > 0; end--) {
            bool swapped = false;

            for (int i = 0; i < end; i++) {
                if (nums[i] > nums[i + 1]) {
                    std::swap(nums[i], nums[i + 1]);
                    swapped = true;
                }
            }

            // If no swap happened, the array is already sorted.
            if (!swapped) {
                break;
            }
        }

        return nums;
    }
};
