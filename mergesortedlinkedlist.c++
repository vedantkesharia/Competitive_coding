#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
 
 using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution {
public:
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while (list1 != NULL || list2 != NULL) {
            ListNode *node;
            if (list1 == NULL || (list2 != NULL && list1->val >= list2->val)) {
                node = new ListNode(list2->val);
                list2 = list2->next;
            } else {
                node = new ListNode(list1->val);
                list1 = list1->next;
            }
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};

void displayLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage of mergeTwoLists
    ListNode* list1 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(6)));

    cout << "List 1: ";
    displayLinkedList(list1);

    cout << "List 2: ";
    displayLinkedList(list2);

    Solution solution;

    // Merge the two sorted lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    displayLinkedList(mergedList);

    return 0;

}