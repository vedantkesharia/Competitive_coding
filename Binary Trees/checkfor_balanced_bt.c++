#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return dfsheight(root) != -1;
    }

    int dfsheight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftheight = dfsheight(root->left);
        if (leftheight == -1)
        {
            return -1;
        }
        int rightheight = dfsheight(root->right);
        if (rightheight == -1)
        {
            return -1;
        }
        if (abs(leftheight - rightheight) > 1)
        {
            return -1;
        }

        return 1 + max(leftheight, rightheight);
    }
};