class Solution {
public:
    bool isPalindrome(int x) {
        double remainder = 0;
        double reverseNum = 0;
        int temp = x;

        if( x < 0 )
            return false;
        if (x < 10)
            return true;    

        while( temp !=0 )
        {
            remainder = temp % 10;
            reverseNum = reverseNum * 10 + remainder;
            temp /= 10;
        }
        
        return x == reverseNum;
    }
};