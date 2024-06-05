class Solution {
public:
int romanToInt(string s) {
    int sum = 0;
    size_t i = 0;

    while ( i < s.size() )
    {
        if( s.at(i) == 'I')
        {
            if( i + 1 < s.size() && (s.at(i+1) == 'V' || s.at(i+1) == 'X') )
            {
                if( s.at(i+1) == 'V' )
                    sum += 4;
                else if( s.at(i+1) == 'X' )
                    sum += 9;
                i++;      
            }
            else
                sum += 1;  
        }  
        else if( s.at(i) == 'X')
        {
            if( i + 1 < s.size() && (s.at(i+1) == 'L' || s.at(i+1) == 'C') )
            {
                if( s.at(i+1) == 'L' )
                    sum += 40;
                else if( s.at(i+1) == 'C' )
                    sum += 90;
                i++;      
            }
            else
                sum += 10;       
        }
        else if( s.at(i) == 'C' )
        {
            if( i + 1 < s.size() && (s.at(i+1) == 'D' || s.at(i+1) == 'M') )
            {
                if( s.at(i+1) == 'D' )
                    sum += 400;
                else if( s.at(i+1) == 'M' )
                    sum += 900;
                i++;     
            }
            else
                sum += 100;                             
        }
        else if( s.at(i) == 'V')
            sum += 5;    
        else if( s.at(i) == 'L')
            sum += 50;    
        else if( s.at(i) == 'D')
            sum += 500;    
        else if( s.at(i) == 'M')
            sum += 1000;

        i++;        
    }
    return sum;  
    }
};