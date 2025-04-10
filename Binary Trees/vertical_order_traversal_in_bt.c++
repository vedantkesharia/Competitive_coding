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

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p =q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                q.push({node->left, {x - 1, y + 1}});
            }
            if(node->right){
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> result;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};