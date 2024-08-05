class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> subSum {};
        const long MODULO = 1000000007;

        for( long i = 0 ; i < nums.size() ; ++i )
        {
            long long sum = 0;
            for( long j = i ; j < nums.size() ; ++j )
            {
                sum += nums[j];
                subSum.emplace_back(sum);
            }
        }

        sort(subSum.begin(), subSum.end());

        return accumulate(subSum.begin() + left - 1, subSum.begin() + right, 0L)%MODULO;
    }
};