//TC: 0(n)
//MC: 0(n)

int toInt(string &s,bool neg)
{    
    int len = s.size();
    string dummy;

    if(len<10)
    {
        dummy.assign(10-len,'0');        
    }        
    dummy+=s;    

    if(dummy>to_string(INT_MAX) || dummy.size()>10)
    {
        return neg == true ? INT_MIN : INT_MAX;
    } 
 
    int power[10]= {1};
    for(int i=1;i<10;i++)
    {
        power[i]=10*power[i-1];
    }
    
    int num = 0;    
    for(int i=0;i<len;i++)
    {
        num+=(s[i]-'0')*power[len-i-1];
    }
    
    return neg == true ? -num : num;
}
int myAtoi(string s) 
{
    bool neg = false;
    string num = "";
    
    int index = 0;
    while(s[index]==' ')
    {
        index++;
    }
    
    if(s[index]=='-') neg=true, index++;
    else if(s[index]=='+') index++;

    while(s[index]=='0') index++;   

    
    while(s[index]>='0' && s[index]<='9')
    {
        num+=s[index];
        index++;
    }          
    
    if(num=="") return 0;   
    return toInt(num,neg);   
}