
typedef struct 
{
    int a[30002];   
    int top;
    int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() 
{
    
    MinStack * stk = (MinStack *)malloc(sizeof(MinStack));
    
    stk->top = -1;
    
    stk->min = INT_MAX;
    
    return stk;

}

int isStackEmpty(MinStack *obj)
{
    if(obj->top == -1)
        return 1;
   
    else
        return 0;
}

int isStackFull(MinStack *obj)
{
    if(obj->top == 30002-1)
        return 1;
   
    else
        return 0;
}

void minStackPush(MinStack* obj, int val) 
{
    if(isStackFull(obj))
        return;
    
    obj->a[++(obj->top)] = val;
   
    if(val <= obj->min)
    
    {
        obj->min = val;
    }

}

void minStackPop(MinStack* obj) 
{
    if(isStackEmpty(obj))
        return;
    
    int ele = obj->a[(obj->top)--];
   
    if(ele == obj->min)
    {
        
        int i=0;
        
        obj->min = INT_MAX;
        
        for(i=0; i<=obj->top; i++)
        {
            if(obj->a[i] <= obj->min)
    
            {
                obj->min = obj->a[i];
            }
            
        }
    }
}

int minStackTop(MinStack* obj) 
{
    return obj->a[obj->top];
}

int minStackGetMin(MinStack* obj) 
{
    return obj->min;
}

void minStackFree(MinStack* obj) 
{
    free(obj);    
}


/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
