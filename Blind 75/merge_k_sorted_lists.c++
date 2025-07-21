class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push({lists[i]->val,lists[i]});
            }
        }
            ListNode* dummy = new ListNode(-1);
            ListNode* temp = dummy;
            while(!pq.empty()){
                auto p = pq.top();
                temp->next  = p.second;
                pq.pop();
                if(p.second->next!=NULL){
                    pq.push({p.second->next->val,p.second->next});
                }
                temp = temp->next;
            }
        return dummy->next;
    }
};