class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int>dp(size+1,0);

        dp[0] = 0;
        dp[1] = 0;

        for( int i = 2 ; i <= size ; ++i )
        {
            if( dp[i-1] + cost[i-1] < dp[i-2] + cost[i-2] )
                dp[i] = dp[i-1] + cost[i-1];
            else
               dp[i] = dp[i-2] + cost[i-2];  
        }

        return dp[size];
    }
};