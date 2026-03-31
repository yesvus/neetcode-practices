/*
This sort compares elements with the previous sorted array, moves the original array to right, overwrites the current Pair while he finds the correct position for the new Pair
*/ 


#include <string>
#include <vector>

class Pair {
public:
    int key;
    std::string value;

    Pair(int key, const std::string& value) : key(key), value(value) {}
};

class Solution {
public:
    std::vector<std::vector<Pair>> insertionSort(std::vector<Pair>& pairs) {

        if (pairs.empty()) {
            return {};
        }
        else if (pairs.size() == 1) {
            return {pairs};
        }
        
        std::vector<std::vector<Pair>> result;
        result.push_back(pairs);

        for (int i = 1; i < pairs.size(); i++) {
            Pair current = pairs[i];
            int j = (i - 1);

            while (j >= 0 && pairs[j].key > current.key) {
                pairs[j + 1] = pairs[j];
                j--;
            }
            pairs[j + 1] = current;
            result.push_back(pairs);
        }

        return result;
    }
};
