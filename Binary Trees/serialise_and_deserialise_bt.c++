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
#include <string>
#include <sstream>

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


class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            queue<TreeNode*> q;
            string result = "";
            if (root == nullptr) {
                return result;
            }
            q.push(root);
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if(node==nullptr){
                    result += "#,";
                }
                else{
                    result += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }

            }
            return result;
        }
TreeNode* deserialize(string data) {
    if (data.empty()) {
        return nullptr;
    }

    queue<TreeNode*> q;
    stringstream s(data);
    string str;

    
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        
        if (getline(s, str, ',')) {
            if (str == "#") {
                node->left = nullptr;
            } else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
        }

        
        if (getline(s, str, ',')) {
            if (str == "#") {
                node->right = nullptr;
            } else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
    }

    return root;
}
};
