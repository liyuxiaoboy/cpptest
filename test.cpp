#include <string>
#include <vector>
#include <map>

bool compare(std::string tmp , std::string mword){
    int master=0; int count=0;
    for (int i=0; i<tmp.size();i++){
        char dic=tmp[i];
        for(;master<mword.size();master++){
            if(dic==mword[master]){
                count++;
                break;
            }
        }
    }
    if(count==tmp.size()){
        return true;
    }
    else{
        return false;
    }

}

std::vector<std::string> sort(std::vector<std::string>& result){
    std::map<char,std::string> sortdic;
    for(int i=0;i<result.size();i++){
        sortdic[result[i][1]]=i;
    }
    std::vector<std::string> sortresult;
    std::map<char,std::string>::iterator it;
    for(it=sortdic.begin();it!=sortdic.end();it++){
        sortresult.push_back((*it).second);
    }
    return sortresult;
    
}

class Solution {
public:
    std::vector<std::string> solve(std::string mword, int n, std::vector<std::string> dictwords) {
        std::vector<std::string> result;
        for(int i=0; i<n-1; i++){
           std::string tmp= dictwords[i];
            if(compare(tmp,mword)){
                result.push_back(tmp);
            }
        }
        std::vector<std::string> sortR=sort(result);
      return sortR;
    }
};