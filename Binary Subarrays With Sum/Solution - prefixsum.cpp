class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        int sum = 0, count = 0;
        prefixCount[0] = 1;

        for (int num : nums) {
            sum += num;

            if (prefixCount.find(sum - goal) != prefixCount.end()) {
                count += prefixCount[sum - goal];
            }
            prefixCount[sum]++;
        }

        return count;
    }
};