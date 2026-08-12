class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                for(int j = i+1; j < s.length(); j++){
                    if(s[j]==')'){
                        count = count +2 ;
                        s[j]= 'a';
                        break;
                    }
                }
            }
        }
        return n - count;
    }
};