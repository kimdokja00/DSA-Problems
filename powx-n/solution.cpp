class Solution {
public:
    double myPow(double x, int n) {
        double r = 1.0;
        long long m = n;
        if ( m < 0) {
            x = 1 / x;
            m = -m;
        }

        while (m > 0) {
            if (m % 2 != 0) {
                r *= x;
            }
            x *= x;
            m /= 2;

            
        }return r;
        }
    };