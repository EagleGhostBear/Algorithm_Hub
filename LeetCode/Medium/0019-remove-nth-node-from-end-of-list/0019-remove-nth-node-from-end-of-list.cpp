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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* now = head;
        vector<int> v;
        while(now){ v.push_back(now->val); now = now->next; }
        if(v.size() == 1) return nullptr;
        int idx = v.size() - n;
        if(idx == 0) {head = head->next; return head;}
        now = head;
        int cnt = 0;
        while(now->next){
            if(cnt + 1 == idx) now->next = now->next->next;
            if(now->next) now = now->next;
            cnt++;
        }
        return head;
    }
};