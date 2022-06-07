//MC: 0(n)
//TC: 0(n)

bool isValid(string s) 
{
    stack<char> store;
    for(auto &str : s)        
    {        
        switch (str)
        {
        case ')':
            if(!store.empty() && store.top()=='(')   store.pop();
            else return false;
            break;
        case '}':
            if(!store.empty() && store.top()=='{')   store.pop();
            else return false;
            break;
        case ']':
            if(!store.empty() && store.top()=='[')   store.pop();
            else return false;
            break;
        
        default:
            store.push(str);
            break;
        }
    }

    if(store.empty()) return true;
    return false;
}
