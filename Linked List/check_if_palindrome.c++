#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode* reverseLinkedList(ListNode* head){
            if(head==NULL || head->next==NULL){
                return head;
            }
            ListNode* newHead = reverseLinkedList(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = nullptr;
            return newHead;
        }
        bool isPalindrome(ListNode* head) {
            if(head==NULL || head->next==NULL){
                return true;
            }
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast->next!=nullptr && fast->next->next!=nullptr){
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode* newHead = reverseLinkedList(slow->next);
            ListNode* first = head;
            ListNode* second = newHead;
            while(second!=nullptr){
                if(first->val!=second->val){
                    reverseLinkedList(newHead);
                    return false;
                }
                first=first->next;
                second=second->next;
            }
            reverseLinkedList(newHead);
            return true;
        }
        
    };