class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        int numerator = 0, denominator = 1; 

        int currNumerator, currDenominator;
        char divideOperator;
        while( ss >> currNumerator >> divideOperator >> currDenominator ) 
        {
            numerator = numerator * currDenominator + currNumerator * denominator;
            denominator *= currDenominator;

            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;

            if( ss.peek() != '+' && ss.peek() != '-' )
                break;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};