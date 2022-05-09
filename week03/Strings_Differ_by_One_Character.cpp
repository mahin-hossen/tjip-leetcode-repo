//MC : 0(n*m) 
//TC : 0(n*m)
// where n is number of word in Dict and m is length of word
bool differByOne(vector<string>& dict) 
{
	int lenWord = dict[0].size();
	int lenDict = dict.size();

	for(int i=0;i<lenWord;i++)
	{
		unordered_set<string> seen;		
		for(int j=0;j<lenDict;j++)
		{
			char ch = dict[j][i];
			dict[j][i]='*';

			if(seen.count(dict[j])) return true;
            seen.insert(dict[j]);			
            dict[j][i] = ch;
		}
	}
	
	return false;
} 


/*
//MC : 0(n*m) 
//TC : 0(n*m*m)
// where n is number of word in Dict and m is length of word
bool differByOne(vector<string>& dict) 
{
	int lenWord = dict[0].size();
	int lenDict = dict.size();

	for(int i=0;i<lenWord;i++)
	{
        unordered_set<string> seen;		
        for(int j=0;j<lenDict;j++)
        {
            string str = dict[j].substr(0,i)+dict[j].substr(i+1);//0(m)

            if(seen.count(str)) return true;
            seen.insert(str);	
        }
	}
	
	return false;
}

*/
