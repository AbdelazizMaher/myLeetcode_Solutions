class Solution {
public:
    int search(vector<int>& nums, int target) {
    #if 1    
        /* Solution 1 */
        int start = 0 , middle = 0;
        int end = nums.size() - 1;

        while( start <= end )
        {
            middle = (start + end)/2;

            if( target < nums.at(middle) )
                end = middle - 1;
            else if( target > nums.at(middle) )
                start = middle + 1;
            else if( target == nums.at(middle) )
                return middle;
        }

        return -1;
    #endif     
        /* Solution 2 */
    #if 0     
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        int pos = it - nums.begin();

        if (pos < nums.size() && nums.at(pos) == target)
            return pos; 
        return -1;
    #endif    
    }
};