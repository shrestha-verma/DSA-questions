class Solution {
private:
    double powerHelper(double x, long long n) {
        // Base Case: 
        if (n == 0) return 1.0;

        // Even power: 
        if (n % 2 == 0) {
            double half = powerHelper(x, n / 2);
            return half * half;
        }
        // Odd power:
        else {
            return x * powerHelper(x, n - 1);
        }
    }

public:
    double myPow(double x, int n) {
        long long exp = n;

        
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }

        return powerHelper(x, exp);
    }
};