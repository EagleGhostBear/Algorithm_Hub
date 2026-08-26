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
    ListNode* swapPairs(ListNode* head) {
        ListNode* nowNode = head;
        ListNode* prevNode = nullptr;
        while(nowNode && nowNode->next){
            ListNode* nextNode = nowNode->next;
            ListNode* tmp = nextNode->next;
            if(prevNode) prevNode->next = nextNode;
            else head = nextNode;
            nextNode->next = nowNode;
            nowNode->next = tmp;
            prevNode = nowNode;
            nowNode = tmp;
        }
        return head;
    }
};