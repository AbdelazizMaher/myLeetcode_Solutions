class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> prefix;

        candidates.erase(remove_if(candidates.begin(), candidates.end(),
        [target](const int& val) {
            return val > target;
        }),
        candidates.end());
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, combinations, prefix, 0, target);
        return combinations;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& prefix, int startIndex, int target) {
        if( target == 0 ) combinations.push_back(prefix);
        else
        {
            for( int i = startIndex ; i < candidates.size() ; ++i )
            {
                if( candidates[i] > target ) break;
                
                prefix.push_back(candidates[i]);
                backtrack(candidates, combinations, prefix, i, target - candidates[i]);
                prefix.pop_back();
            }
        }
    }
};