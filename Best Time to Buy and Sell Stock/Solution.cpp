class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int maxProfit = 0;

        for( int i = 1 ; i < prices.size() ; ++i )
        {
            int currProfit = prices[i] - minSoFar;
            if( currProfit > maxProfit )
                maxProfit = currProfit;
            if( minSoFar > prices[i] )
                minSoFar = prices[i];
        }
        return maxProfit;
    }
};