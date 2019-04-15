#include <string>
#include <vector>
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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        void preorder(TreeNode* node, 
                      TreeNode* search,
                      std::vector<TreeNode*> &path, 
                      std::vector<TreeNode*> &result, 
                      int &finish){
            if(!node || finish==1){
                return;
            }
            path.push_back(node);
            if(node==search){
                finish=1;
                result=path;
            }

            preorder(node->left, search, path, result, finish);
            preorder(node->right, search, path, result, finish);
            path.pop_back();
        }
        
    }
};