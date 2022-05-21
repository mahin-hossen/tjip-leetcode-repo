/*
TC : 0(N*M) +   0(N*M*4*3^L)    //GenerateTrie() -> 0(M*N)
                                //dfs -> 0(4*3^L)
    where N is number of rows and M is number of column
    where L is maximum length of word

MC : 0(N*M)
*/


vector<int>dr{-1,0,1,0,-1};

class TrieNode
{
public:
    string word;
    TrieNode* next[26];

    TrieNode()
    {
        word = "";
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
};


TrieNode* generateTrie(vector<string> &words)
{
    TrieNode* root = new TrieNode();

    for(auto &wd : words)
    {
        TrieNode* currNode = root;
        for(auto &c : wd)
        {
            if(currNode->next[c-'a']==NULL)
            {
                currNode->next[c-'a'] = new TrieNode();
            } 
            currNode = currNode->next[c-'a'];
        }
        currNode->word = wd;
    }
    return root;
}

void dfs(int x,int y,TrieNode* currNode,vector<vector<char>>&board,vector<string> &wordsOnBoard)
{
    char ch = board[x][y];
    if(ch=='#' || (currNode && currNode->next[ch-'a']==NULL)) return;    
    currNode = currNode->next[ch-'a']; 

    if(currNode && currNode->word.size()>0)
    {
        wordsOnBoard.push_back(currNode->word); 
        currNode->word = "";
    }    

    board[x][y]='#';

    for(int i=0;i<4;i++)
    {
        int X = x+dr[i];
        int Y = y+dr[i+1];

        if(X<0 || Y<0 || X>=board.size() || Y>=board[0].size() || board[X][Y]=='#') 
            continue;

        dfs(X,Y,currNode,board,wordsOnBoard);

    }
    board[x][y]=ch;
}

vector<string> findWords(vector<vector<char>>&board, vector<string>&words)
{
    TrieNode* root = generateTrie(words);

    vector<string> wordsOnBoard;
    int n = board.size();
    int m = board[0].size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dfs(i,j,root,board,wordsOnBoard);
        }
    }

    return wordsOnBoard;
}