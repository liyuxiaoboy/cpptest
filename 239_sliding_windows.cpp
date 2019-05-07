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
using namespace std;

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
        {
            return nums;
        }
        std::vector<int> result;
        std::deque<int> slidingWindow;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k && slidingWindow[0] <= i - k)
            {
                slidingWindow.pop_front();
                while (!slidingWindow.empty() && nums[slidingWindow.front()] < nums[i])
                {
                    slidingWindow.pop_front();
                }
                while (!slidingWindow.empty() && nums[slidingWindow.back()] < nums[i])
                {
                    slidingWindow.pop_back();
                }
            }
            else{
                 while (!slidingWindow.empty() && nums[slidingWindow.front()] < nums[i])
                {
                    slidingWindow.pop_front();
                }
                while (!slidingWindow.empty() && nums[slidingWindow.back()] < nums[i])
                {
                    slidingWindow.pop_back();
                }
            }
            slidingWindow.push_back(i);
            if (i >= k - 1)
            {
                result.push_back(nums[slidingWindow[0]]);
            }
        }
        return result;
    }
};