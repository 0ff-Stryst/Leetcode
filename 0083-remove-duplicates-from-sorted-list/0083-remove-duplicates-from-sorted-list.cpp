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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode* head1 = new ListNode;
        head1 = head;
        ListNode* temp = head->next;
        ;

        while (head != NULL && temp != NULL) {
            if (head->val == temp->val) {
                head->next = temp->next;
                temp = head->next;
            } else {
                head = head->next;
                temp = temp->next;
            }
        }

        return head1;
    }
};