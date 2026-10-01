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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* curr = head;
        int count = 1;
        ListNode* pre = dummy;
        while( count != left){
            pre = pre->next;
            curr = curr->next;
            count++;
        }

        ListNode* xx = curr;

        int count2 = 1;
        int x = right - left + 1;
        ListNode* prev = NULL;
        ListNode* nextt = NULL;
        while( count2 <= x){
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr= nextt;
            count2++;
        }

        pre->next = prev;
        xx->next = curr;

        return dummy->next;

    }
};