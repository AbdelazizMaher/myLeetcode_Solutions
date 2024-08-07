class Solution {
private:
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string tillThousand(int num) {
        string word {};
        if( num/1000 != 0 )
            word = threeDigitsToWords(to_string(num/1000)) + " Thousand ";
        if( num%1000 != 0 )
            word += threeDigitsToWords(to_string(num%1000));   

        return word;       
    }
    string tillMillion(int num) {
        string word {};
        if( num/1000000 != 0 ) 
            word = threeDigitsToWords(to_string(num/1000000)) + " Million ";
        if( num%1000000 != 0 )
            word +=  tillThousand(num%1000000);

        return word;       
    } 
    string tillBillion(int num) { 
        string word = threeDigitsToWords(to_string(num/1000000000)) + " Billion ";
        if( num%1000000000 != 0 )
            word +=  tillMillion(num%1000000000);

        return word;       
    }       
public:
    string numberToWords(int num) {
        string word {};
        int temp {};

        if ( num < 1000 )
            word = threeDigitsToWords(to_string(num));
        else if ( num >= 1000 && num < 1000000 )
            word = tillThousand(num);            
        else if ( num >= 1000000 && num < 1000000000 )
            word = tillMillion(num);           
        else
            word = tillBillion(num);         

        while (!word.empty() && word.back() == ' ')
            word.pop_back();
        
        return word;
    }

    string threeDigitsToWords(string digits) {
        string word {};

        if( digits == "0" )
            return "Zero";

        if ( digits.size() == 3 && digits[0] != '0' )
            word = below20[digits[0] - '0'] + " Hundred ";
        else if (digits.size() == 2 )
            digits = "0" + digits;
        else
            digits = "00" + digits;    

        if ( stoi( digits.substr(1, 2)) <= 19 )
            word += below20[stoi(digits.substr(1, 2))];
        else if ( below20[stoi(digits.substr(2, 1))] == "" )
            word += tens[digits[1] - '0'];   
        else
            word += tens[digits[1] - '0'] + " " + below20[stoi(digits.substr(2, 1))];

        while (!word.empty() && word.back() == ' ')
            word.pop_back();

        return word;    
    }
};