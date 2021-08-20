struct ListNode*fun(struct ListNode*p) {
        if(p==0)
            return p;
       struct ListNode*t=p;
        int c=0;
        while(p->next!=0&&p->val==p->next->val) {
            p=p->next;
            c=1;
        }
        if(c==0)
        {
        t->next=fun(p->next);
       
        return t;
        }
        return fun(p->next);
    }

struct ListNode* deleteDuplicates(struct ListNode* head){
    return fun(head);
}
