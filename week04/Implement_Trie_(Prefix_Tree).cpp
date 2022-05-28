/*
TC : 0(N)

insert() -> 0(N)
search() -> 0(N)
startswith() -> 0(N)
        where N is length of word


MC : 0(N*M)
        where N is length of word and M is number of string
*/

class TrieNode
{
public:
    bool isWord;
    TrieNode* next[26];

    TrieNode()
    {
        isWord = false;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string str) 
    {
        TrieNode* currNode = root;
        for(auto &c:str)
        {
            int order = c-'a';
            if(currNode->next[order]==NULL)
            {
                currNode->next[order] = new TrieNode();
            }

            currNode = currNode->next[order];
        }
        currNode->isWord = true;
    }
    
    bool search(string str,bool existsAsPrefix = false) 
    {
        TrieNode* currNode = root;
        for(auto &c:str)
        {
            int order = c-'a';    
            if(currNode->next[order]==NULL) 
                return false;

            currNode = currNode->next[order];       
        }
        return currNode && (currNode->isWord || existsAsPrefix);  
    }
    
    bool startsWith(string str) 
    {
        return search(str,true);
    }
};
