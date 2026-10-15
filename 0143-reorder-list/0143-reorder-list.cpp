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
    void reorderList(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* x = helper(slow->next);
        slow->next = NULL;
        ListNode* y = head;

        while (x != NULL) {
            ListNode* tmp1 = y->next;
            ListNode* tmp2 = x->next;

            y->next = x;
            x->next = tmp1;

            y = tmp1;
            x = tmp2;
        }
    }

    ListNode* helper(ListNode* x) {
        ListNode* next = NULL;
        ListNode* curr = x;
        ListNode* prev = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};