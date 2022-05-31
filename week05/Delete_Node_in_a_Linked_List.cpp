/*
TC : 0(1)
MC : 0(1)
*/
void deleteNode(ListNode* node) 
{
    auto next = node->next;
    *node = *next;
    
    delete(next);
}