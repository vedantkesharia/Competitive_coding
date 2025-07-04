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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left==NULL && cur->val>val){
                cur->left = new TreeNode(val);
                return root;
            }
            else if(cur->right==NULL && cur->val<val){
                cur->right = new TreeNode(val);
                return root;
            }
            if(cur->val>val){
                cur = cur->left;
            }
            else if(cur->val<val){
                cur = cur->right;
            }
        }
        return root;
    }
};




