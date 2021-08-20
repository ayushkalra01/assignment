
bool isPalindrome(struct ListNode* head){
   struct ListNode*p,*q;
   int a[100001]; 
    p=head;
    int c=0;
    while(p) {
        a[c++]=p->val;
        p=p->next;
    }
    
    for(int i=0;i<c/2;i++) {
        if(a[i]!=a[c-i-1])return 0;
    }
    return 1;
}
