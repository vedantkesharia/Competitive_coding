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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, int> inMap;
            for (int i = 0; i < inorder.size(); ++i) {
                inMap[inorder[i]] = i;
            }

            return buildTreePostorderInorder(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1, inMap);
        }

        TreeNode* buildTreePostorderInorder(vector<int>& inorder, vector<int>& postorder, int postStart, int postEnd, int inStart, int inEnd, unordered_map<int, int>& inMap) {
            if (postStart > postEnd || inStart > inEnd) {
                return nullptr;
            }

            TreeNode* root = new TreeNode(postorder[postEnd]);
            int inRootIndex = inMap[root->val];
            int leftTreeSize = inRootIndex - inStart;

            root->left = buildTreePostorderInorder(inorder, postorder, postStart, postStart + leftTreeSize - 1, inStart, inRootIndex - 1, inMap);
            root->right = buildTreePostorderInorder(inorder, postorder, postStart + leftTreeSize, postEnd - 1, inRootIndex + 1, inEnd, inMap);

            return root;
        }
    };