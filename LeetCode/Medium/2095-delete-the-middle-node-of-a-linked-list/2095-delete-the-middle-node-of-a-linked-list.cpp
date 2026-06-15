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
        if(head->next == nullptr) return nullptr;
        ListNode* slowP = head;
        ListNode* fastP = head;
        while(fastP->next){
            int cnt = 2;
            while(cnt-- && fastP->next) fastP = fastP->next;
            if(fastP->next) slowP = slowP->next;
            else{
                if(slowP->next) slowP->next = slowP->next->next;
                else slowP->next = nullptr;
            }
        }
        return head;
    }
};