#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parStack;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!parStack.empty() && parStack.top() == closeToOpen[c]) {
                    parStack.pop();
                } else {
                    return false;
                }
            } else {
                parStack.push(c);
            }
        }
        return parStack.empty();
    }
};
