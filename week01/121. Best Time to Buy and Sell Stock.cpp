int maxProfit(vector<int> &prices)
{
	int maxElement = prices.back(), profit = 0;
	for(int i=prices.size()-1;i>=0;i--)//0(n)
	{
		if(prices[i]>maxElement)
        {
            maxElement=prices[i];
            continue;
        }
        if(maxElement-prices[i]>profit) profit = maxElement-prices[i];
    }
    if(profit<0) return 0;
    return profit;
}