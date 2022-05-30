/*
TC : 0(N) // N = length of LinkedList
MC : 0(1)
*/

ListNode* reverseList(ListNode* head) 
{
    if(!head) return head;
    
    auto curr = head;
    ListNode* prev = NULL;        
    
    while(curr)
    {            
        auto next = curr->next;            
        curr->next = prev;
        prev = curr;
        curr = next;            
    }
    
    return prev;        
    
}