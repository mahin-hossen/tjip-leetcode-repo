//MC: 0(n)
//TC: 0(1)

unordered_map<string,int>buckets;
Logger()
{
	buckets.clear();
}
bool shouldPrintMessage(int timestamp, string message)
{
	if(buckets.count(message) && buckets[message]+10>=timestamp)
	{
		buckets[message]=timestamp;
		return true;
	}
	return false;
}
