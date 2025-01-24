class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) zeroCount++;
            else if (nums[i] == 1) oneCount++;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (zeroCount-- > 0) nums[i] = 0;
            else if (oneCount-- > 0) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};