class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalFreq = count(nums.begin(), nums.end(), 1);

        if ( totalFreq == 0 || totalFreq == nums.size() )
            return 0;

        nums.insert(nums.end(), nums.begin(), nums.begin() + totalFreq);

        int zerosNo = count(nums.begin(), nums.begin() + totalFreq, 0);
        int minZeros = zerosNo;

        for( int i = 1 ; i < nums.size() - totalFreq ; ++i )
        {
            if( int temp =  zerosNo + nums[i-1] - nums[i+totalFreq-1];  zerosNo = temp, zerosNo< minZeros )  
                minZeros = zerosNo;       
        }

        return minZeros;    
    }
};