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
    ListNode* deleteMiddle(ListNode* head) {
        vector<ListNode*> v;
        queue<ListNode*> q;
        if(head) q.push(head);
        while(q.size()){
            ListNode* now = q.front(); q.pop();
            v.push_back(now);
            if(now->next) q.push(now->next);
        }
        if(v.size() == 1) return nullptr;
        int mid = v.size() / 2;
        v[mid - 1]->next = v[mid]->next;
        return head;
    }
};