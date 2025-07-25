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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            return head->next;
        }
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;
        return head;
        
    }
};
