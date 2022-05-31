/*
TC :
    get() -> 0(N)
    addAtHead -> 0(1)
    addAtTail -> 0(N)
    addAtIndex -> 0(N)
    deleteAtIndex -> 0(N)

MC :  0(N)    
    //where N = number of addAtIndex operation

*/
class MyLinkedList {
    const static int DUMMY = INT_MIN;
public:
    class LinkedList
    {
    public:
        int val;
        LinkedList* next;
        
        LinkedList(int value,LinkedList* nxt)
        {
            val = value;
            next = nxt;
        }    
    };
    
private:
        LinkedList* head;
        int len;
    
public:
    MyLinkedList() 
    {
        head = new LinkedList(DUMMY,NULL);
        len = 0;
    }
    
    int get(int index) 
    {
        if(index<0 || index>=len) return -1;
        
        auto curr = head->next;
        while(index--)
        {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) 
    {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) 
    {
        addAtIndex(len,val);    
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index<0 || index>len) return;
        
        auto curr = head;
        while(index--)
        {
            curr = curr->next;
        }
        auto newNode = new LinkedList(val,curr->next);
        curr->next = newNode;
        len++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index<0 || index>=len) return;
        
        auto curr = head;
        while(index--)
        {
            curr = curr->next;
        }        
        auto del = curr->next;
        curr->next = curr->next->next;
        delete(del);
        len--;
    }
};