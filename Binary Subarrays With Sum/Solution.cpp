class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int arrLength = nums.size();
        int count = 0;

        for (int i = 0; i < arrLength; ++i) {
            int sum = 0;
            for (int j = i; j < arrLength; ++j) {
                sum += nums[j];
                if(sum > goal)
                    break;
                if (sum == goal)
                    count++;
            }
        }
        return count;
    }
};