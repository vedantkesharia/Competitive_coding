#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p==NULL||q==NULL){
                return (p==q);
            }      
            return (p->val==q->val) 
            && isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
    }
};

int main() {
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    Solution solution;

    if (solution.isSameTree(tree1, tree2)) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are not the same." << endl;
    }


    return 0;
}