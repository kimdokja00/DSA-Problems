class Solution {
public:
    string reverseWords(string s) {
        string r;
        int n = s.length();
        for(int i= n-1;i >-1;i--){
            if(s[i]==' ' && (s[i+1] != ' '&& i>0) || i==0){
                if(s[i]!=' '&& i==0){
                    r+=s[i];
                }
                for(int k = i+1;k<n && s[k]!=' ';k++){
                    r += s[k];
                }
                
                if(i == 0){
                    break;               }
                    r+= ' ';
            }
        }for(int i=0;i<r.length();i++){
        if(r[r.length()-1]== ' '){
                    r.pop_back();
                }}
        for(int i=0;i<r.length();i++){
        if(r[0]== ' '){
                    r.erase(0,1);
                }}
        return r;
    }
};