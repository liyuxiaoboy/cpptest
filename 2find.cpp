#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
     vector<int> searchRange(vector<int>& nums, int target) {
        int begin=0;
        int end=nums.size()-1;
        int index=-1;
        while(index==-1){
            int mid=(begin+end)/2;
            if(target==nums[mid]){
                index=mid;
            }
            else if(target<nums[mid]){
                if(mid==0||target>nums[mid-1]){
                    index=-2;
                }
                end=mid-1;
            }
            else if(target>nums[mid]){
                if(mid==nums.size()-1||target<nums[mid+1]){
                    index=-2;
                }
                begin=mid+1;
            }
        }
        if(index==-2){
            vector<int> result={-1,-1};
            return result;
        }
        cout<<index<<endl;
        int st=index;
        int ed=index;
        while(st>0&&nums[st]==nums[index]){
            st--;
        }
        while(ed<nums.size()&&nums[ed]==nums[index]){
            ed++;
        }
        vector<int> result;
        result.push_back(st+1);
        result.push_back(ed-1);
        return result;
    }
};

int main()
{
    int num[]= {5,7,7,8,8,8,8,10};
    vector<int> input;
    for(int i=0;i<8;i++){
        input.push_back(num[i]);
    }
    Solution solve;
    vector<int> result = solve.searchRange(input,8);
    cout<<result[0]<<result[1]<<endl;
}