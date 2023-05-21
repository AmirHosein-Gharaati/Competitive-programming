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
        ListNode* it = head, *temp;
        ListNode* prev;

        for(int i = 0 ; i < n; i++) {
            it = it->next;
        }

        temp = head;

        while(it != nullptr) {
            it = it->next;
            prev = temp;
            temp = temp->next;
        }

        if(prev != nullptr) {
            prev->next = temp->next;
        } else {
            return head->next;
        }

        return head;
    }
};