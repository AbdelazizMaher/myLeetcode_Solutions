class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSums {};
        int size = nums.size();

        sort(nums.begin(), nums.end());

        if ( nums[0] > 0 ) 
            return threeSums;

        for( int i = 0 ; i < size - 2 ; ++i )
        {
            if (i == 0 || (i - 1 >= 0 && nums[i-1] != nums[i]))
            {
                int target = -nums[i];
                int left = i + 1;
                int right = size - 1;

                while( left < right )
                {
                    if( (left - 1 >= i + 1) && nums[left-1] == nums[left] )
                    {
                        left++;
                        continue;
                    }
                    if( (right + 1 <= size - 1) && nums[right+1] == nums[right] )
                    {
                        right--;
                        continue;                    
                    }
                    if (nums[left] + nums[right] < target) 
                        left++;
                    else if (nums[left] + nums[right] > target) 
                        right--; 
                    else
                    {
                        threeSums.push_back({nums[i], nums[left], nums[right]});
                        left++;
                    }                       
                }
            }
        }
        return threeSums;
    }
};