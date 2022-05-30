/*
TC : 0(N) // N = length of LinkedList
MC : 0(1)
*/
bool hasCycle(ListNode *head) 
{
    auto slow = head, fast = head;       
    while(fast && fast->next)
    {            
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    } 
    
    return false;        
}