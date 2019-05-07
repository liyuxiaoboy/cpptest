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
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head){
            return NULL;
        }
        if(head&&!head->next){
            return head;
        }
        ListNode* result=head->next;
        ListNode* pre=new ListNode(0);
        while(head&&head->next){
            ListNode* node1=head;
            ListNode* node2=head->next;
            ListNode* tmp=node2->next;
            node1->next=tmp;
            node2->next=node1;
            pre->next=node2;
            pre=node1;
            head=tmp;
        }
        return result;
    }
};