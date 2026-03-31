#include <unordered_map>
#include <vector>

class Solution {
public:
    bool hasDuplicate(const std::vector<int>& nums) {
        std::unordered_map<int, bool> map;

        for(int i = 0; i < nums.size() ; i++) {
            if (map[nums[i]]) {
                return true;
            }
            else {
                map[nums[i]] = true;
            }
        }
        return false;
    }
};