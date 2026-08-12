class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        vector<char> result;
        if (n == 0){
            return true;
        }
        for(int i = 0;i < n; i++){
            if(isalnum(s[i])){
                result.push_back(tolower(s[i]));
            }
        }
        int x = result.size();
        for(int j = 0 ; j< x/2; j++){
            if(result[j]!= result[x-1-j]){
                return false;
            }
        }
        return true;
    }
};