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
        int leftHeight(TreeNode* root){
            int height = 0;
            while(root != nullptr){
                height++;
                root = root->left;
            }
            return height;
        }
        int rightHeight(TreeNode* root){
            int height = 0;
            while(root != nullptr){
                height++;
                root = root->right;
            }
            return height;
        }
        int countNodes(TreeNode* root) {
            if(root == nullptr){
                return 0;
            }
            int left = leftHeight(root);
            int right = rightHeight(root);
            if(left == right){
                return (1 << left) - 1; 
            }
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
      
    };