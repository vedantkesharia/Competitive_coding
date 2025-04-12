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
#include <queue>
#include <set>

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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> inMap;
            for (int i = 0; i < inorder.size(); ++i) {
                inMap[inorder[i]] = i;
            }

            return buildTreePreorderInorder(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap);
        }

        TreeNode* buildTreePreorderInorder(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& inMap) {
            if (preStart > preEnd || inStart > inEnd) {
                return nullptr;
            }

            TreeNode* root = new TreeNode(preorder[preStart]);
            int inRootIndex = inMap[root->val];
            int leftTreeSize = inRootIndex - inStart;

            root->left = buildTreePreorderInorder(preorder, inorder, preStart + 1, preStart + leftTreeSize, inStart, inRootIndex - 1, inMap);
            root->right = buildTreePreorderInorder(preorder, inorder, preStart + leftTreeSize + 1, preEnd, inRootIndex + 1, inEnd, inMap);

            return root;
        }

    };