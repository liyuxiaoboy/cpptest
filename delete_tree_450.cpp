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
  TreeNode* BST_search(TreeNode *node, int value, TreeNode* &parent){
      while(node){
          if(node->val==value){
              break;
          }
          parent=node;
          if(value<node->val){
              node=node->left;
          }
          else{
              node=node->right;
          }
      }
      return node;
  }

  void delete_single_node(TreeNode* parent, TreeNode* node){
      if(node->val<parent->val){
          if(node->left&&!node->right){
              parent->left=node->left;
          }
          else if(!node->left&&node->right){
              parent->left=node->right;
          }
          else{
              parent->left=NULL;
          }
      }
      if(node->val>parent->val){
          if(node->left&&!node->right){
              parent->right=node->left;
          }
          else if(!node->left&&node->right){
              parent->right=node->right;
          }
          else{
              parent->right=NULL;
          }
      }
  }

  TreeNode* find_successor(TreeNode* node,TreeNode* &parent){
      parent=node;
      TreeNode* ptr=node->right;
      while(ptr->left){
          parent=ptr;
          ptr=ptr->left;
      }
      return ptr;
  }
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
       TreeNode* parent=NULL;
       TreeNode* node= BST_search(root,key,parent);
       if(!node){
           return root;
       }
       if(node->left&&node->right){
           TreeNode* successor=find_successor(node,parent);
           delete_single_node(parent,successor);
           node->val=successor->val;
           return root;
       }
       if(parent){
           delete_single_node(parent,node);
           return root;
       }
       if(node->left){
           root=node->left;
       }
       else{
           root=node->right;
       }
       return root;

    }
};