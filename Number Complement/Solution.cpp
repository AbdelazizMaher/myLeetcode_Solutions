class Solution {
public:
    int findComplement(int num) {
        int oneCount = num;
        for( int i = 0 ; oneCount != 0 ; ++i )
        {
            oneCount >>= 1;    
            num ^= (1 << i);            
        }
        return num;       
    }
};