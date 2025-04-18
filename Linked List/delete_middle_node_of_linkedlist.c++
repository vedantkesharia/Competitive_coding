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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return NULL;
        }
       ListNode* slow = head;
       ListNode* fast = head;
       fast = fast->next->next;
       while(fast!=nullptr && fast->next!=nullptr){
           slow = slow->next;
           fast = fast->next->next;
       }
       ListNode* middleNode = slow->next;
       slow->next = slow->next->next;
       delete middleNode;
       return head;
    }
};