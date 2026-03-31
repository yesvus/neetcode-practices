#include <string>
#include <utility>
#include <vector>

class Pair {
public:
    int key;
    std::string value;

    Pair(int key, const std::string& value) : key(key), value(value) {}
};


class Solution {
public:
    // Implementation of Insertion Sort
    std::vector<std::vector<Pair>> insertionSort(std::vector<Pair>& pairs) {
        int n = pairs.size();
        std::vector<std::vector<Pair>> res;  // To store the intermediate states of the array

        for (int i = 0; i < n; i++) {
            int j = i - 1;
            
            // Move elements that are greater than key one position ahead
            while (j >= 0 && pairs[j].key > pairs[j + 1].key) {
                std::swap(pairs[j], pairs[j + 1]);
                j--;
            }

            // Clone and save the entire state of the array at this point
            res.push_back(pairs);
        }
        return res;
    }
};
