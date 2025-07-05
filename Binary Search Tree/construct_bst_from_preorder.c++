#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>

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
    TreeNode* helperfunction(vector<int>& preorder,int& i,int ub){
        int n = preorder.size();
        if(i==n || preorder[i]>ub){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helperfunction(preorder,i,root->val);
        root->right = helperfunction(preorder,i,ub);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helperfunction(preorder, i, INT_MAX);
    }
};