#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        list<int> list1;
        while (head != nullptr) {
            list1.push_back(head->val);
            head = head->next;
        }

        k = k % list1.size();

        auto it = list1.begin();
        advance(it, list1.size() - k);

        reverse(list1.begin(), it);
        reverse(it, list1.end());
        reverse(list1.begin(), list1.end());

        ListNode *rotatedHead = nullptr;
        ListNode *current = nullptr;

        for (int val : list1) {
            if (rotatedHead == nullptr) {
                rotatedHead = new ListNode{val, nullptr};
                current = rotatedHead;
            } else {
                current->next = new ListNode{val, nullptr};
                current = current->next;
            }
        }

        return rotatedHead;
    }
};
void displayList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;
    ListNode *head = new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{4, new ListNode{5, nullptr}}}}};
    int k = 2;

    cout << "Original List: ";
    displayList(head);

    ListNode *rotatedHead = solution.rotateRight(head, k);

    cout << "Rotated List: ";
    displayList(rotatedHead);

    while (rotatedHead != nullptr)
    {
        ListNode *temp = rotatedHead;
        rotatedHead = rotatedHead->next;
        delete temp;
    }

    return 0;
}
