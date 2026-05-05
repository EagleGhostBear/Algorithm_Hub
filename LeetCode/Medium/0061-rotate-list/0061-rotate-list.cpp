/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> v;
        queue<ListNode*> q;
        if(head) q.push(head);
        while(q.size()){
            ListNode* now = q.front(); q.pop();
            v.push_back(now->val);
            if(now->next) q.push(now->next);
        }
        int sz = v.size();
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        if(sz) k %= sz;
        for(int i=0; i<sz; i++){
            int idx = (i-k < 0 ? i-k+sz : i-k);
            cur->next = new ListNode(v[idx]);
            cur = cur->next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};