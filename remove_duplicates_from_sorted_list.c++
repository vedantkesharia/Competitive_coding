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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;

      while(current!=nullptr && current->next!=nullptr){
        if(prev->next->val==current->next->val){
            prev->next=current->next;
            delete current;
            current = prev->next;
        }
        else
            {
                prev = prev->next;
                current = current->next;
            }
        }

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

    ListNode *originalHead = new ListNode(1);
    originalHead->next = new ListNode(1);
    originalHead->next->next = new ListNode(2);
    originalHead->next->next->next = new ListNode(3);
    originalHead->next->next->next->next = new ListNode(3);

    cout << "Original Linked List: ";
    displayList(originalHead);

    ListNode *result = solution.deleteDuplicates(originalHead);

    cout << "Updated Linked List: ";
    displayList(result);

    while (result != nullptr)
    {
        ListNode *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}