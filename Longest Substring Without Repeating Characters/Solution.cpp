class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0 , left = 0 , right = 0 , strLength =  s.length();
        unordered_map<char,int> charFreq {};

        while( right < strLength )
        {
            charFreq[s[right]]++; 

            auto isValid = [&](){
                for( auto [key, freq] : charFreq )
                {
                    if( freq > 1 )
                        return false;
                }
                return true;
            };

            while( left < right && !isValid() )
            {
                charFreq[s[left]]--;
                left++;
            }

            if( int length = right - left + 1; length > maxLength)
                maxLength = length;

            right++;    
        }
        return maxLength;
    }
};