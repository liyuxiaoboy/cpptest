#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 bool cmp(ListNode* a,ListNode* b){
     return a->val<b->val;
 }
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<ListNode*> node_vec;
        for(int i=0;i<lists.size();i++){
            ListNode* head=lists[i];
            while(head){
                node_vec.push_back(head);
                head=head->next;
            }
        }
        if(node_vec.size()==0){
            return NULL;
        }
        std::sort(node_vec.begin(),node_vec.end(),cmp);
        for(int i=1;i<node_vec.size();i++){
            node_vec[i-1]->next=node_vec[i];
        }
        node_vec[node_vec.size()-1]->next=NULL;
        return node_vec[0];
    }
};