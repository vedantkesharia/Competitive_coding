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
    ListNode *sortList(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        list<int> list1;

        while (head != NULL)
        {
            list1.push_back(head->val);
            head = head->next;
        }

        list1.sort();

        // for (int val : list1)
        // {
        //     temp->next = new ListNode(val);
        //     temp = temp->next;
        // }
        list<int> :: iterator iter;
        for (iter = list1.begin(); iter != list1.end(); iter++)
        {
            temp->next = new ListNode(*iter);
            temp = temp->next;
        }

        return dummy->next;
    }
};

void displayLinkedList(ListNode *head)
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

    ListNode *head = new ListNode(3, new ListNode(1, new ListNode(4, new ListNode(2))));

    cout << "Original Linked List: ";
    displayLinkedList(head);

    Solution solution;

    ListNode *sortedList = solution.sortList(head);

    cout << "Sorted Linked List: ";
    displayLinkedList(sortedList);

    return 0;
}
