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
        if ( head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* current = head;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* temp = dummy;
        while( current != NULL && current->next != NULL){
            if ( current->next != NULL && current->val == current->next->val){
                int x = current->val;
                while( current != NULL && current->val == x){
                    current = current->next;
                }
                temp->next = current;
            }
            else{
                temp  = current;
                current = current->next;
            }
        }
        return dummy->next;
    }
};