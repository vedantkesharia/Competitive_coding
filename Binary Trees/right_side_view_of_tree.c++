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

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> result;
            recursion(root, 0, result);
            return result;

        }

        vector<int> recursion(TreeNode* root, int level, vector<int>& result){
            if(root == nullptr){
                return result;
            }
            if(level == result.size()){
                result.push_back(root->val);
            }
            recursion(root->right, level + 1, result);
            recursion(root->left, level + 1, result);
            return result;
        }
    };