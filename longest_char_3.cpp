#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin =0;
        int result =0;
        std::string word="";
        int char_map[128]={0};
        for(int i=0;i<s.length();i++){
            char_map[s[i]]++;
            if(char_map[s[i]]==1){
                word+=s[i];
                if(result<word.length()){
                    result=word.length();
                }
            }
            else{
                while(char_map[s[i]]==2){
                    char_map[s[begin]]--;
                    begin++;
                }
                word="";
                for(int j=begin;j<=i;j++){
                    word+=s[j];
                }
            }
        }
        return result;
    }
};