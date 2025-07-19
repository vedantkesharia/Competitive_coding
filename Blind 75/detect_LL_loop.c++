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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!= nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Create a list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr (no cycle)
    ListNode* noCycleHead = new ListNode(1);
    noCycleHead->next = new ListNode(2);
    noCycleHead->next->next = new ListNode(3);
    noCycleHead->next->next->next = new ListNode(4);
    noCycleHead->next->next->next->next = new ListNode(5);

    // Create a list with a cycle: 10 -> 20 -> 30 -> 40 -> points back to 20
    ListNode* cycleHead = new ListNode(10);
    cycleHead->next = new ListNode(20);
    cycleHead->next->next = new ListNode(30);
    cycleHead->next->next->next = new ListNode(40);
    cycleHead->next->next->next->next = cycleHead->next; // cycle: 40 -> 20

    Solution sol;
    
    cout << "Testing list without cycle: ";
    cout << (sol.hasCycle(noCycleHead) ? "Cycle detected" : "No cycle") << endl;

    cout << "Testing list with cycle: ";
    cout << (sol.hasCycle(cycleHead) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}

