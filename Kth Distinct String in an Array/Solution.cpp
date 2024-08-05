class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int kth = 0;
        for( int i = 0 ; i < arr.size() ; ++i )
        {   
            for( int j = 0 ; j < arr.size() ; ++j )
            {
                if( i == j && j == arr.size()-1 )
                    kth++;
                if( i == j )
                    continue;
                else if( arr[i] == arr[j] )
                    break;
                else if( arr[i] != arr[j] && j == arr.size()-1 )
                    kth++;    
            }
            if( kth == k )
                return arr[i];
        }
        return "";        
    }
};