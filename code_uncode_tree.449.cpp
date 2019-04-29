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

void change_int_to_string(int val,std::string& str_val){
    std::string tmp;
    while(val){
        tmp+=val%10+'0';
        val=val/10;
    }
    for(int i=tmp.length()-1;i>=0;i--){
        str_val+=tmp[i];
    }
    str_val+="#";
}

void BST_preorder(TreeNode* node, std::string &data){
    if(!node){
        return;
    }
    std::string str_val;
    change_int_to_string(node->val,str_val);
    data+=str_val;
    BST_preorder(node->left,data);
    BST_preorder(node->right,data);
}

void BST_insert(TreeNode* node, TreeNode* insert_node){
    if(insert_node->val<node->val){
        if(node->left){
            BST_insert(node->left,insert_node);
        }
        else{
            node->left=insert_node;
        }
    }
    else{
        if(node->right){
            BST_insert(node->right,insert_node);
        }
        else{
            node->right=insert_node;
        }
    }
}

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        std::string data;
        BST_preorder(root,data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(data.length()==0){
            return NULL;
        }
        std::vector<TreeNode*> node_vec;
        int val=0;
        for(int i=0;i<data.length();i++){
            if(data[i]=='#'){
                node_vec.push_back(new TreeNode(val));
                val=0;
            }
            else{
                val=val*10+(data[i]-'0');
            }
        }
        for(int i=1;i<node_vec.size();i++){
            BST_insert(node_vec[0],node_vec[i]);
        }
        return node_vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));