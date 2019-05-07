#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        int length = s.length();
        std::stack<char> temp;
        for (int i = 0; i < length; i++)
        {
            if (temp.empty())
            {
                if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    return false;
                }
                temp.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (temp.top() == '(' && s[i] == ')')
                {
                    temp.pop();
                    continue;
                }
                else if (temp.top() == '{' && s[i] == '}')
                {
                    temp.pop();
                    continue;
                }
                else if (temp.top() == '[' && s[i] == ']')
                {
                    temp.pop();
                    continue;
                }
                return false;
            }
            else{
                temp.push(s[i]);
            }
        }
        if(temp.empty()){
            return true;
        }
        return false;
    }
};