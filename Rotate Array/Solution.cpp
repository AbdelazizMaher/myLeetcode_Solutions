class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= nums.size();

        reverse(nums, 0, size - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, size - 1);
    }

    void reverse(vector<int>& nums, int start, int end)
    {
        while( start < end )
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
    }
};