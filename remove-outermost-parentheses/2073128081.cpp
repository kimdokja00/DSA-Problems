class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string r;
        for ( int i =0 ; i<s.length();i++){
            if(s[i]=='('){
                if(depth >0){
                    r += '(';
                }depth++;
            }
            if(s[i]==')'){
                depth--;
                if(depth >0){
                    r += ')';
                }
            }
            
        }return r;
    }
};