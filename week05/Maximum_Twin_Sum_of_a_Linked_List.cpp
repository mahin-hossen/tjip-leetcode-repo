/*
TC : 0(N)  //where N is length of Linkedlist
MC : 0(1)
*/
void reverseHalfList(ListNode* prevNode,ListNode* &curr)
{  
    ListNode* prev = NULL;
    while(curr)
    {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;            
    }     
    prevNode->next = prev;
    
    return;        
}

int pairSum(ListNode* head) 
{
    auto slow = head, fast = head;
    
    while(fast->next && fast->next->next)//until fast reaches on sec last element
    {
        slow = slow->next;
        fast = fast->next->next;
    }        
    
    reverseHalfList(slow,slow->next);//reverses half of list
    
    auto half = slow->next;
    auto curr = head;        
    int maxTwinSum = INT_MIN;
    
    while(half)
    {
        int currPairSum = curr->val+half->val;
        maxTwinSum = max(currPairSum,maxTwinSum);
        
        half = half->next;
        curr = curr->next;
    }
    
    reverseHalfList(slow,slow->next);//returns list to original states
    
    return maxTwinSum;
}