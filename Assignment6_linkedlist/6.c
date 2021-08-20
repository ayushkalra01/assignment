/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
 if(head==0)
            return 0;
        
        struct ListNode*p=head,*q=head;
        
        int c=n;
        while(c!=0) {
            head=head->next;
            c--;
        }
        
        if(head==0) {
            return p->next;
        }
        while(head->next!=0) {
            p=p->next;
            head=head->next;
        }
        p->next=p->next->next;
        
        return q;
    }

