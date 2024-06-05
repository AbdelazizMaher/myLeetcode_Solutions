class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        size_t i = 0;
        unordered_map<string,int> RtoI {
            {"I",1},
            {"V",5},
            {"X",10},
            {"L",50},
            {"C",100},
            {"D",500},
            {"M",1000},
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900},
        };
        while( i < s.size() )
        {
            if( (i + 1 < s.size())  &&  (RtoI.find(s.substr(i, 2)) != RtoI.end()) )
            {
                sum += RtoI[s.substr(i,2)];
                i +=2;
            }
            else
            {
                sum += RtoI[s.substr(i,1)];
                i++;
            }
        }
        return sum;
        }
};