#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         std::sort(s.begin(),s.end());
//         std::sort(t.begin(),t.end());
//         if(s==t){
//             return true;
//         }
//         return false;
//     }
// };

class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        std::unordered_map<char, int> count;
        for (int i = 0; i < s.size(); i++)
        {
            if (count.find(s[i]) == count.end())
            {
                count[s[i]] = 1;
            }
            else
            {
                count[s[i]]++;
            }
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (count.find(t[i]) == count.end())
            {
                return false;
            }
            else
            {
                count[t[i]]--;
            }
        }
        unordered_map<char, int>::iterator iter;
        for (iter = count.begin(); iter != count.end(); iter++)
        {
            if (iter->second != 0)
            {
                return false;
            }
        }
        return true;
    }
};
