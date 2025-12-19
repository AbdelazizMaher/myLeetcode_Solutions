class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int ans {};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i]) {
                nums[++ans] = nums[i];
            }
        }
        return ++ans;
    }
};