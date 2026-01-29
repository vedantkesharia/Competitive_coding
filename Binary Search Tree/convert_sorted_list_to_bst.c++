#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    ListNode* curr;

    TreeNode* buildBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* leftChild = buildBST(left, mid - 1);

        TreeNode* root = new TreeNode(curr->val);
        root->left = leftChild;

        curr = curr->next;

        root->right = buildBST(mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        curr = head;
        return buildBST(0, n - 1);
    }
};
