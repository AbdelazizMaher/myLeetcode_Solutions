class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int arrLength = nums.size();
        int count = 0 , sum = 0;
        int left  = 0, right = 0;

        while (right < arrLength) {
            sum += nums[right];

            while (left < right && sum > goal) {
               sum -= nums[left]; 
               left++;
            }

            if (sum == goal) {
                count++;
                int tempLeft = left;
                int tempSum = sum - nums[left];
                while (tempSum == goal && tempLeft < right) {
                    count++;
                    tempLeft++;
                    tempSum -= nums[tempLeft];
                }
            }

            right++;
        }
    return count;
    }
};