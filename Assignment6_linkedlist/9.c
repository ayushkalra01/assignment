/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

     struct ListNode* reverse(struct ListNode *head,struct ListNode *end) {
        struct ListNode *p,*q,*r;
        
        p=head;
        q=head->next;
        head->next=0;
        while(q!=end) {         
                r=q->next;
                q->next=p;
            p=q;
                q=r;
        }
        return p;
    }

struct ListNode* rotateRight(struct ListNode* head, int k){
       struct ListNode *p,*q,*r,*a1,*a2;
       struct ListNode*pq=head;
        int c=0;
        if(pq==0)
            return 0;
        while(pq!=0){pq=pq->next;c++;}
        k=k%c;
        if(k==0||c==0) {
            return head;
        }
        if(head->next==0)
            return head;
        head=reverse(head,0);
        p=head;
        q=0;
        r=0;
        while(k--) {
            q=p;
            p=p->next;
        }
        //head->q;
        //p->0
        a1=reverse(head,p);
        a2=reverse(p,0);
        
        p=a1;
        while(p->next!=0)p=p->next;
        p->next=a2;
        return a1;
}
