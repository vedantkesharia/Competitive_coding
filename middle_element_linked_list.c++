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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        ListNode *temp2 = head;
        int length = 0;
        while(head->next!=NULL){
            head = head->next;
            length++;
        }
        int mid = (length+1)/2;
        int i = 0;
        while(i<mid){
            temp2=temp2->next;
            i++;
        }

        return temp2;

    }
};
 

 int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));

    Solution solution;
    ListNode *middle = solution.middleNode(head);

    if (middle != nullptr)
        cout << "Middle node value: " << middle->val << endl;
    else
        cout << "List is empty." << endl;

    return 0;
}