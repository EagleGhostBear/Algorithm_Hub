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
    int pairSum(ListNode* head) {
        int ans = 0;
        vector<int> v;
        queue<ListNode*> q;
        if(head) q.push(head);
        while(q.size()){
            ListNode* now = q.front(); q.pop();
            v.push_back(now->val);
            if(now->next) q.push(now->next);
        }
        int sz = v.size();
        for(int i=0; i<sz/2; i++) ans = max(ans, v[i] + v[sz - 1 - i]);
        return ans;
    }
};