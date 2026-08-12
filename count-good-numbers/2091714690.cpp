class Solution {
private:
    long long MOD = 1000000007;

    // O(log n) time
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long count = power(20, n / 2);

        if (n % 2 != 0) {
            count = (count * 5) % MOD;
        }

        return count;
    }
};