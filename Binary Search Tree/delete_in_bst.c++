#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std; 

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* extremeRightFinder(TreeNode *node){
        while(node->right!=NULL){
            node = node->right;
        }
        return node;
    }
public:
    TreeNode* helper(TreeNode* node){
        if(node->left==NULL) return node->right;
        if(node->right==NULL) return node->left;
        TreeNode* extremeright = extremeRightFinder(node->left);
        extremeright->right = node->right;
        return node->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
           return helper(root);
        }
        TreeNode* dummy = root;
        while(dummy!=NULL){
            if(dummy->left != NULL && dummy->left->val==key){
                dummy->left = helper(dummy->left);
                break;
            }
            if(dummy->right != NULL && dummy->right->val==key){
                dummy->right = helper(dummy->right);
                break;
            }
            if(dummy->val>key){
                dummy=dummy->left;
            }
            else if(dummy->val<key){
                dummy=dummy->right;
            }
        }
        return root;
    }
};






