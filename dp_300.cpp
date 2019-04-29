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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        std::vector<int> dp(nums.size(),0);
        dp[0]=1;
        int LIS=1;
        for(int i=1;i<dp.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            if(LIS<dp[i]){
                LIS=dp[i];
            }
        }
        return LIS;
    }
};