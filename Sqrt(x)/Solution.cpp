class Solution {
public:
    int mySqrt(int x) {
        int left = 0 , right = x;
        int mid;

        if( x == 0 || x == 1 )
            return x;

        while( left <= right )
        {
            mid = (left + right) / 2;
            if( mid == x/mid )
                return mid;
            else if( mid < x/mid )
                left = mid + 1;
            else if( mid > x/mid )
                right = mid - 1;                
        }
        return right;
    }
};