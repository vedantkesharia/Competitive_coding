#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;


//100% Beats!!


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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy = new ListNode();
        ListNode *dummy2 = new ListNode();
        dummy->next = head;
        ListNode *temp = head;
        ListNode *temp2 = dummy;
        ListNode *temp3 = dummy2;

        while (temp != nullptr)
        {
            if (temp->val < x)
            {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            else
            {
                temp3->next = temp;
                temp3 = temp3->next;
            }
            temp = temp->next;
        }

        temp3->next = nullptr;      
        temp2->next = dummy2->next;

        return dummy->next;
    
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

    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    cout << "Original List: ";
    displayList(head);

    ListNode *result = solution.partition(head, 3);

    cout << "Partitioned List: ";
    displayList(result);

    return 0;
}