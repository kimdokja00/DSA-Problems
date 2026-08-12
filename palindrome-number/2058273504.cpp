class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            cout<<"false";
            }
            int n=x;
            long r = 0;
            while(n>0){
              
               r = r*10 + n%10;
                n = n/10;
            }
             return x == r;
}
};
