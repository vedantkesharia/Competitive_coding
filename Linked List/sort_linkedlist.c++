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
        ListNode* findMiddle(ListNode* head) {
           ListNode* slow = head;
           ListNode* fast = head->next;
           while(fast!=nullptr && fast->next!=nullptr){
               slow = slow->next;
               fast = fast->next->next;
           }
           return slow;
        }
    
        ListNode*mergeTwoLists(ListNode* l1, ListNode* l2){
            if(l1==nullptr) return l2;
            if(l2==nullptr) return l1;
           ListNode* dummyNode = new ListNode(-1);
            ListNode* temp = dummyNode;
            while(l1!=nullptr && l2!=nullptr){
                if(l1->val<l2->val){
                    temp->next = l1;
                    temp = l1;
                    l1 = l1->next;
                }else{
                    temp->next = l2;
                    temp = l2;
                    l2 = l2->next;
                }
    
            }
            if(l1!=nullptr) temp->next = l1;
            if(l2!=nullptr) temp->next = l2;
            return dummyNode->next;
        }
        ListNode* sortList(ListNode* head) {
            if(head==nullptr || head->next==nullptr) return head;
            ListNode* middle = findMiddle(head);
            ListNode* nextToMiddle = middle->next;
            middle->next = nullptr;
            ListNode* left = sortList(head);
            ListNode* right = sortList(nextToMiddle);
            ListNode* sortedList = mergeTwoLists(left, right);
            return sortedList;
        }
    };