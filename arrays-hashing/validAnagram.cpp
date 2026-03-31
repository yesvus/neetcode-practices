#include <unordered_map>
#include <string>


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> counts;
        for (char character : s) {
            counts[character]++;
        }

        for (char character : t) {
            if (counts[character]) {
                counts[character]--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
