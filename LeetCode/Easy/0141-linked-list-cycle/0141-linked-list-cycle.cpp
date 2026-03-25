/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int cnt = 0;
        queue<ListNode*> q;
        if(head) q.push(head);
        while(q.size() && cnt < 1e4 + 2){
            ListNode* now = q.front(); q.pop();
            cnt++;
            if(now->next) q.push(now->next);
        }
        if(cnt > 1e4) return true;
        return false;
    }
};