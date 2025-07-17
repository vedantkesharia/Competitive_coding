#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>
#include <cmath>

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
        ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp!=nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
        }
    };