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
        ListNode* oddEvenList(ListNode* head) {
            if (head == NULL || head->next ==NULL){
                return head;
            }
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = head->next;
            while(odd->next!=nullptr && odd->next->next!=nullptr){
                odd->next = odd->next->next;
                even->next = even->next->next;
                odd= odd->next;
                even = even->next;
            }
            odd->next = evenHead;
            return head;
        }
    };