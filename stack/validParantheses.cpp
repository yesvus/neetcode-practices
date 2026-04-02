#include <string>
#include <stack>

using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<char> ParStore;

        for (char currPar : s) {
            if (currPar == '(' || currPar == '[' || currPar == '{')
                ParStore.push(currPar);
            else if (currPar == ')' || currPar == ']' || currPar == '}')
                if (!ParStore.empty() && revertPar(ParStore.top()) == currPar) {
                    ParStore.pop();
                }
                else {
                    return false;  
                }
            else return false;
                         
        }
    if (ParStore.empty())
        return true;
    else return false;
    }

private:
    char revertPar(char Par) {
        if (Par == '(') 
            return ')';
        else if (Par == ')') 
            return ')';
        else if (Par == '[') 
            return ']';
        else if (Par == ']')
            return '[';
        else if (Par == '{')
            return '}';
        else if (Par == '}')
            return '{';
        else return -1;
    }

};
