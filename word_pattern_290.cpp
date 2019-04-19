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
    bool wordPattern(string pattern, string str) {
        std::map<std::string ,char> word_map;
        char used[128]={0};
        std::string word;
        int pos=0;
        str.push_back(' ');
        for(int i=0;i<str.length();i++){
            if(str[i]==' '){
                if(pos==pattern.length()){
                    return false;
                }
                if(word_map.find(word)==word_map.end()){
                    if(used[pattern[pos]]==1){
                        return false;
                    }
                    word_map[word]=pattern[pos];
                    used[pattern[pos]]=1;
                }
                else{
                    if(word_map[word]!=pattern[pos]){
                        return false;
                    }
                }
                word="";
                pos++;
            }
            else{
                word+=str[i];
            }
        }
        if(pos!=pattern.length()){
            return false;
        }
        return true;
    }
};