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

class Solution
{
public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         ListNode *dummy = new ListNode();
//         ListNode *temp = dummy;
//         ListNode *temp1 = head;
//         ListNode *temp2 = head;
//         ListNode *temp3;
//         // temp3 -> next = temp2;
//          temp3 = dummy;
//         int length = 0;
//         while (temp1->next != NULL)
//         {
//             temp1 = temp1->next;
//             length++;
//         }
//         int i = 0;
//         while(i<(length-n)){
//             temp2 = temp2->next;
//             temp3 = temp3-> next;
           
//         }
//          temp2-> next = temp3-> next;
//             delete temp3;
// return dummy->next;
//     }
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode();
    dummy->next = head;

    ListNode *temp = dummy;
    ListNode *temp2 = head;

    int length = 0;
    while (temp2 != nullptr) {
        temp2 = temp2->next;
        length++;
    }


    int i = 0;
    while (i < (length - n )) { 
        temp = temp->next;
        i++;
    }

    temp->next = temp->next->next;

    return dummy->next;
}
};


void displayList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    

    cout << "Original List: ";
    displayList(head);


    Solution solution;


    int n = 2;
    ListNode *modifiedList = solution.removeNthFromEnd(head, n);

    cout << "Modified List: ";
    displayList(modifiedList);

    return 0;
}
