#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <bits/stdc++.h>

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



class BSTIterator {
stack <TreeNode*> st;
bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(reverse==false) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(reverse==true) node = node->right;
            else node = node->left;
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator left(root,false);
        BSTIterator right(root,true);
        
        int i = left.next();
        int j = right.next();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j>k){
                j=right.next();
            }
            else{
                i=left.next();
            }
        }
        return false;
    }
};


