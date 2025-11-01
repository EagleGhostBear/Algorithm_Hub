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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy;
        ListNode* tail = &dummy;

        map<int, bool> m;
        for(auto n : nums) m[n] = true;
        while(head){
            if(!m[head->val]){
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
        }
        tail->next = nullptr;

        return dummy.next;
    }
};