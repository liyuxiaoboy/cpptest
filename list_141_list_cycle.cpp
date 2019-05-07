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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (!head )
        {
            return false;
        }
        ListNode *FlagNode = head;
        while (FlagNode)
        {   head=head->next;
            FlagNode=FlagNode->next;
            if(!FlagNode){
                return false;
            }
            FlagNode=FlagNode->next;
            if (FlagNode == head)
            {
                return true;
            }
        }
        return false;
    }
};

// class Solution
// {
//   public:
//     bool hasCycle(ListNode *head)
//     {
//         if(!head||!head->next){
//             return false;
//         }
//         ListNode* FlagNode=head->next;
//         while(FlagNode->next&&FlagNode->next->next){
//             FlagNode=FlagNode->next->next;
//             head=head->next;
//             if(FlagNode==head){
//                 return true;
//             }
//         }
//         return false;
//     }
// };