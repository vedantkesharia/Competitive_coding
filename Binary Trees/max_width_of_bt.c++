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
        int widthOfBinaryTree(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }      
    
            queue<pair<TreeNode*, unsigned long long>> q;
            int ans = 0;
            q.push({root, 0});
    
            while (!q.empty()) {
                int size = q.size();
                unsigned long long minIndex = q.front().second;
                unsigned long long firstIndex = 0, lastIndex = 0;
    
                for (int i = 0; i < size; i++) {
                    auto [node, idx] = q.front(); q.pop();
                    unsigned long long curr_id = idx - minIndex;
    
                    if (i == 0) firstIndex = curr_id;
                    if (i == size - 1) lastIndex = curr_id;
    
                    if (node->left) {
                        q.push({node->left, 2 * curr_id + 1});
                    }
                    if (node->right) {
                        q.push({node->right, 2 * curr_id + 2});
                    }
                }
                ans = max(ans, static_cast<int>(lastIndex - firstIndex + 1));
            }
            return ans;
        }
    };
    