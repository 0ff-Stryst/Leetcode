/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;


        ListNode * one = headA;
        ListNode * two = headB;

        int count1 = 0;
        while( one != NULL){
            count1++;
            one = one->next;
            
        }
        int count2 = 0;
        while(two != NULL){
            count2++;
            two = two->next;

        }
        one = headA;
        two = headB;

        if (count1 > count2) {
            for (int i = 0; i < count1 - count2; i++) {
                one = one->next;
            }
        } else {
            for (int i = 0; i < count2 - count1; i++) {
                two = two->next;
            }
        }

        while( one != two){
            one = one->next;
            two = two->next;

        }  

        return one;
    }
};