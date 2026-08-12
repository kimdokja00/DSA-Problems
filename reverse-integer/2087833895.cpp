class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        long long n = x;
        long long limit = pow(2, 31);
        while (n > 0 || -n>0) {
            result = 10*result + n%10 ;
            n = n/10;
        }
        if( result<limit -1 && result>-limit){
        return result;}
        return 0;
    }
};