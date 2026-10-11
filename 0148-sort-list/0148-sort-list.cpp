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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(newhead);
        return merge(left, right);
    }

    ListNode* merge(ListNode* p1, ListNode* p2) {

        if (p1 == NULL) {
            return p2;
        }
        if (p2 == NULL){
            return p1;
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;


        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        if (p1 != NULL) curr->next = p1;
        if (p2 != NULL) curr->next = p2;

        return dummy.next;
    }
};