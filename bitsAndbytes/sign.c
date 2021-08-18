#include <stdio.h>

int sign(int x) {
    int ans=0;
    if(x>0) {
        ans=1;
    }
    else if(x<0) {
        ans=-1;
    }
    return ans;
}

int main() {
    
    int x, y;
    
    scanf("%d",&x);
    
    int ans = sign(x);
    
    printf("%d\n",ans);
    return 0;
}
