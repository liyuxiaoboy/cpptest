#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <queue>
#include <pair>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        std::vector<int> dp(nums.size(),0);
        
            dp[0]=nums[0];
            dp[1]=std::max(nums[0],nums[1]);
            for(int i=1;i<nums.size();i++){
                dp[i]=std::max(dp[i-2]+nums[i],dp[i-1]);
            }
            return dp[nums.size()-1];
        
    }
};