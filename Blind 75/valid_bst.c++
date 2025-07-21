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
    bool isValidBSThelper(TreeNode* root, long long lowerRange, long long upperRange) {
        if (root == NULL) return true;
        if (root->val <= lowerRange || root->val >= upperRange) return false;

        return isValidBSThelper(root->left, lowerRange, root->val) &&
               isValidBSThelper(root->right, root->val, upperRange);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSThelper(root, LLONG_MIN, LLONG_MAX);
    }
};





