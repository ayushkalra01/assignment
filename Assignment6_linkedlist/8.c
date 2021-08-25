/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

   struct ListNode* fun(struct ListNode* l1,struct ListNode* l2) {
        if(l1==0)return l2;
        if(l2==0)return l1;
        if(l1->val<=l2->val) {
            l1->next=fun(l1->next,l2);
            return l1;
        }
        else {
            l2->next=fun(l1,l2->next);
            return l2;
        }
    }

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
 return  fun(l1,l2);
}
