class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        long long n = x;
        while (n > 0 || -n>0) {
            result = 10*result + n%10 ;
            n = n/10;
        }
        if( result< INT_MAX && result>INT_MIN){
        return result;}
        return 0;
    }
};