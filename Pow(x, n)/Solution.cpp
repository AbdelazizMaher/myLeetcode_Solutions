class Solution {
public:
    double myPow(double x, int n) {
        long long overflow = n;
        if (overflow < 0) {
            x = 1 / x;
            overflow = -overflow;
        }
        return getPower(x, overflow); 
    }
private:
    double getPower(double x, int n) {
       if (n == 0) return 1.0;

        double power = getPower(x, n / 2);

        power *= power;
        if (n % 2 != 0) {
            power *= x;
        }
        return power;
    }
};