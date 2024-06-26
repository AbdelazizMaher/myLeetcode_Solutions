class Solution {
public:
    int addDigits(int num) {
    int sum = 0;
    int flag = 1;
    int remainder = 0;

    while( flag )
    {
        if( num == 0 && sum > 9 )
        {
            num = sum;            
            sum = 0;
        }
        else if (num == 0 && sum < 10 )
        {
            break;
        }
        
        sum += num % 10;
        num /= 10;
    }

    return sum;
    }
};