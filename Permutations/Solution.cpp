class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations{};
        vector<int> prefix{};

        backtrack(nums, permutations, prefix);
        return permutations;        
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& prefix) {
        if (nums.size() == 0) permutations.push_back(prefix);
        else
        {
            for (int i = 0; i < nums.size(); ++i)
            {                    
                prefix.push_back(nums[i]);

                int chosen = nums[i];
                nums.erase(nums.begin() + i);

                backtrack(nums, permutations, prefix);

                nums.insert(nums.begin() + i, chosen);

                prefix.pop_back();
            }
        }
    }
};

