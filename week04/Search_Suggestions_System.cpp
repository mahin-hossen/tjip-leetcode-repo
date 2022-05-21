/*
TC : 0(M*N) + 0(L*3*N)       //GenerateTrie() -> 0(M*N)
                             //dfs -> 0(3*N)

    where M is number of words in products and N is length of word
    where L is length of SearchWord

MC : 0(S) where S is sum of all words length in Products
*/

class TrieNode
{
public:    
    string word;
    TrieNode* next[26];

    TrieNode()
    {
        word = "";
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
};

TrieNode* generateTrie(vector<string>& products)
{
    TrieNode* root = new TrieNode();        
    
    for(auto &product : products)
    {
        TrieNode* currNode = root;
        for(auto &c : product)
        {
            if(currNode->next[c-'a']==NULL)
            {
                currNode->next[c-'a'] = new TrieNode();
            }
            currNode = currNode->next[c-'a'];
        }
        currNode->word = product;
    }
    
    return root;
}  

void dfs(TrieNode* u,vector<string>& threeWords)
{        
    if(u==NULL || threeWords.size()==3) return;
    
    if(u->word.size()!=0 && threeWords.size()<3)
    {
        threeWords.push_back(u->word);            
    }
    
    for(int i=0;i<26;i++)
    {
        dfs(u->next[i],threeWords);                
    }
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
{
    TrieNode* root = generateTrie(products);
    
    vector<vector<string>> suggestions;       
    
    for(auto &c : searchWord)
    {
        root = root && root->next[c-'a'] ? root->next[c-'a'] : NULL;            
        vector<string> threeWords;

        dfs(root,threeWords);
        suggestions.push_back(threeWords);            
    }        
    
    return suggestions;
}