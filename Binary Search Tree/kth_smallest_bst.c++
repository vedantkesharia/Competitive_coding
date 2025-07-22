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
    void inorder(TreeNode* root, int&k, int&count, int&kthsmallest){
        if(count>k || root==NULL) return;
    
        inorder(root->left,k,count,kthsmallest);
        count++;
        if(count==k){
            kthsmallest = root->val;
            return;
        }
        inorder(root->right,k,count,kthsmallest);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;    
        int kthsmallest = INT_MIN;
        inorder(root,k,count,kthsmallest);
        return kthsmallest;
    }
};






