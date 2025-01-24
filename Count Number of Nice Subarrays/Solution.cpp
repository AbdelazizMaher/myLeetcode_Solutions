class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int numSize = nums.size();
        int count = 0, oddCount = 0;
        int left = 0, right = 0;

        while (right < numSize) {
            if (nums[right] % 2 != 0) oddCount++;

            while (oddCount > k && left < right) {
               if (nums[left] % 2 != 0) oddCount--;
               left++; 
            }

            if (oddCount == k) {
                count++;
                int tempLeft = left;
                int tempCount = oddCount;
                if (nums[tempLeft] % 2 != 0) tempCount--;
                while (tempCount == k && tempLeft < right) {
                    count++;
                    tempLeft++;
                    if (nums[tempLeft] % 2 != 0) tempCount--;
                }
            }

            right++;
        }
        return count;
    }
};