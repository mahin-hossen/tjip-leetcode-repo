/*
TC : 0(N)
MC : 0(1)
        //where N is length of given Linkedlist
*/
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    auto currNode = head, nthNode = head;
    ListNode* prevNode = nullptr;
    
    while(n--)
    {
        currNode = currNode->next;
    }
    
    while(currNode)
    {
        prevNode = nthNode;
        currNode = currNode->next;            
        nthNode = nthNode->next;
    }
    
    if(prevNode == nullptr)
    {
        head = head->next;
    }
    else
    {
        prevNode->next = nthNode->next;
    }       
    
    delete(nthNode);        
    return head;
}