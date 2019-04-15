#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4){
            return false;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%4){
            return false;
        }
        std::sort(nums.begin(),nums.end(),cmp);
        int bucket[4]={0};
        return generate(0,nums,sum/4,bucket);
    }

private:
    bool cmp(int a,int b){
    return a > b;
    }
    
    bool generate(int i,vector<int>& nums, int target, int bucket[]){
        if(i>nums.size()){
            return bucket[0]==target&&bucket[1]==target&&
            bucket[2]==target&&bucket[3]==target;
        }
        for(int j=0;j<4;j++){
            if(bucket[j]+nums[i]>target){
                continue;
            }
            bucket[j]+=nums[i];
            if(generate(i+1,nums,target,bucket)){
                return true;
            }
            bucket-=nums[i];
        }
        return false;
    }
};