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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        list<int> firsthalf;
        ListNode *current1 = head;
        while (current1 != slow)
        {
            firsthalf.push_back(current1->val);
            current1 = current1->next;
        }

        list<int> secondhalf;
        ListNode *current2 = slow;
        while (current2 != nullptr)
        {
            secondhalf.push_front(current2->val);
            current2 = current2->next;
        }
        return equal(firsthalf.begin(), firsthalf.end(), secondhalf.begin());
    }
};

void displayList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    std::cout << "Original List: ";
    displayList(head);

    // Check if the linked list is a palindrome
    bool result = solution.isPalindrome(head);

    if (result)
    {
        std::cout << "The linked list is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}