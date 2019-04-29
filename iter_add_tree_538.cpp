#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
  
  void travel_tree(TreeNode* node, int sum){
      if(!node){
          return;
      }
      travel_tree(node->right,sum);
      sum+=node->val;
      travel_tree(node->left,sum);
  }
 
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        travel_tree(root,sum);
        return root;
    }
};