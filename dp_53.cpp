#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size(),0);
        dp[0]= nums[0];
        int max_res=dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=std::max(dp[i-1]+nums[i],nums[i]);
            if(dp[i]>max_res){
                max_res=dp[i];
            }
        }
        return max_res;
    }
};