/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
        if(head==0)
            return 0;
        
   struct ListNode*p=head,*q=head;
        int t=1;
        while(q!=0&&(p!=q||t)) {
            q=q->next;
            t=0;
            if(q==0)
                return 0;
            p=p->next;
            q=q->next;
        }
        p=head;
        if(q==0)return 0;
        while(p!=q) {
            p=p->next;
            q=q->next;
        }
        
        return p;
}
