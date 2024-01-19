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

// The line ListNode *dummy = new ListNode(); is creating a new dynamically allocated instance of the ListNode struct using the new operator in C++
// ListNode *dummy: This declares a pointer named dummy that is intended to point to a ListNode object. In C++, pointers are variables that store memory addresses.

// = new ListNode();: This dynamically allocates memory for a new instance of the ListNode struct using the new operator. The ListNode() part calls the default constructor of the ListNode struct, which initializes the val member to 0 and the next member to nullptr.

// dummy:
// dummy is a dummy node, i.e., a placeholder node that is not part of the actual result but is useful in simplifying the code for handling the edge cases and initializing the result linked list.
// It is initialized with a new empty ListNode using new ListNode() in the beginning.
// The real result linked list starts from dummy->next because dummy itself does not contain any meaningful value.
// At the end of the process, dummy->next points to the head of the result linked list.

// temp:
// temp is a temporary pointer used to iterate through the result linked list while building it.
// It starts pointing to dummy, and as new nodes are added to the result, temp is moved to the last node to maintain the current end of the result list.
// It is essential for the correct placement of new nodes in the result linked list.
// At the end of the process, temp points to the last node of the result linked list.


class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
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
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    cout << "Input Linked List 1: ";
    displayLinkedList(l1);
    cout << "Input Linked List 2: ";
    displayLinkedList(l2);

    // Create a Solution object
    Solution solution;

    // Call the addTwoNumbers function
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Display the result linked list
    cout << "Sum Linked List: ";
    displayLinkedList(result);
}