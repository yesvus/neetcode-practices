#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasDuplicate(const vector<int>& nums) {
        unordered_map<int, bool> map;

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