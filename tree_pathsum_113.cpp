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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        int path_value = 0;
        preorder(root, path_value, sum, path, result);
        return result;
    }

  private:
    void preorder(TreeNode *node, int &path_value, int sum,
                  std::vector<int> &path,
                  std::vector<std::vector<int>> &result)
    {
        if (!node)
        {
            return;
        }
        path_value += node->val;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL && path_value == sum)
        {
            result.push_back(path);
        }
        preorder(node->left, path_value, sum, path, result);
        preorder(node->right, path_value, sum, path, result);
        path_value -= node->val;
        path.pop_back();
    }
};