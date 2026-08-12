class Solution {
public:
    string largestOddNumber(string num) {
        string r = num;
       for(int i = num.length()-1;i>-1;i--) {
        if(num[i]%2==0){
            r.erase(i,1);
        }else{break;}
       }return r;
    }
};