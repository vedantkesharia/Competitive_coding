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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *dummy1 = new ListNode(0);
    ListNode *dummy2 = new ListNode(0);
    dummy1->next = headA;
    dummy2->next = headB;

    ListNode *tempA = headA;
    ListNode *tempB = headB;

    while (tempA != tempB)
    {
        tempA = tempA ? tempA->next : headB;
        tempB = tempB ? tempB->next : headA;
    }

    return tempA;
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

    // Example 1
    ListNode *listA = new ListNode(4);
    listA->next = new ListNode(1);
    listA->next->next = new ListNode(8);
    listA->next->next->next = new ListNode(4);
    listA->next->next->next->next = new ListNode(5);

    ListNode *listB = new ListNode(5);
    listB->next = new ListNode(6);
    listB->next->next = new ListNode(1);
    listB->next->next->next = listA->next->next;

    cout << "List A: ";
    displayList(listA);
    cout << "List B: ";
    displayList(listB);

    ListNode *intersectionNode1 = solution.getIntersectionNode(listA, listB);

    if (intersectionNode1 != nullptr)
        cout << "Intersection Node Value: " << intersectionNode1->val << endl;
    else
        cout << "No Intersection" << endl;

    // Example 2
   ListNode *listA2 = new ListNode(1);
listA2->next = new ListNode(9);
listA2->next->next = new ListNode(1);
ListNode *intersectionNode = new ListNode(2);
listA2->next->next->next = intersectionNode;
listA2->next->next->next->next = new ListNode(4);

ListNode *listB2 = new ListNode(3);
listB2->next = new ListNode(2);
listB2->next->next = intersectionNode; // Point to the same node as in listA2


    cout << "\nList A: ";
    displayList(listA2);
    cout << "List B: ";
    displayList(listB2);

    ListNode *intersectionNode2 = solution.getIntersectionNode(listA2, listB2);

    if (intersectionNode2 != nullptr)
        cout << "Intersection Node Value: " << intersectionNode2->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}