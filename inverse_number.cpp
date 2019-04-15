#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<std::pair<int,int>> vec;
        std::vector<int> count;
        for(int i=0;i<nums.size();i++){
            vec.push_back(std::make_pair(nums[i],i));
            count.push_back(0);
        }
        merge_sort(vec,count);
        return count;
    }

private:
    void merge_sort_to_vec(std::vector<std::pair<int,int>>& sub_vec1,
                           std::vector<std::pair<int,int>>& sub_vec2,
                           std::vector<std::pair<int,int>>& vec,
                           std::vector<int> &count){

    }

    void merge_sort(std::vector<std::pair<int,int>>& vec,
                    std::vector<int>& count){

                    }
};
