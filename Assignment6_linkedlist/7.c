/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int l, int r){
   struct ListNode *p=head,*q,*t,*re,*f;
       
       struct ListNode*m=(struct ListNode*)malloc(sizeof(struct ListNode));
        m->val=0;
        m->next=head;
        head=m;
        
        while(m!=0) {
            l--;
            r--;
            
            if(l==0) {
                
                if(m->next->next==0||r==0)return head->next;
               
                p=m;
                q=p->next;
                re=q;
                while(q!=0) {
                    re=re->next;
                    q->next=p;
                    p=q;
                        
                    q=re;
                    if(r==0)break;
                    r--;
                }
          
                m->next->next=q;
                m->next=p;
                break;
            }
            
        m=m->next;
        }
        return head->next;
}
