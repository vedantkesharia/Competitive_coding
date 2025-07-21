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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int depth1 = maxDepth(root->left);
        int depth2 = maxDepth(root->right);
        return max(depth1, depth2)+1;
    }
};

#include <iostream>

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    // [3,9,20,null,null,15,7]

    Solution solution;

    int depth = solution.maxDepth(root);

    cout << "Max Depth of the Binary Tree: " << depth << endl;

    return 0;
}
