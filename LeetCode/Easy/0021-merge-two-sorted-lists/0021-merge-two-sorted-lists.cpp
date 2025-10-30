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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 더미 노드 생성
        ListNode dummy;
        ListNode* tail = &dummy;

        // 두 리스트 모두 순회
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // 남은 리스트 연결
        if (list1 != nullptr) tail->next = list1;
        else tail->next = list2;

        // dummy 다음이 결과 리스트의 시작
        return dummy.next;
    }
};