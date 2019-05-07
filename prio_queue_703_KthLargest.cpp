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

class KthLargest
{
  public:
    KthLargest(int k, vector<int> &nums)
    {
        length = k;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                less_tree.push(nums[i]);
            }
            else if(less_tree.top()<nums[i]){
                less_tree.pop();
                less_tree.push(nums[i]);
            }
            else{
                continue;
            }
        }
    }

    int add(int val)
    {
        if(less_tree.size()<length){
            less_tree.push(val);
        }
        else if(less_tree.top()<val){
                less_tree.pop();
                less_tree.push(val);
            }
        return less_tree.top();
    }

private:
std::priority_queue<int, vector<int>, greater<int>> less_tree;
int length;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */