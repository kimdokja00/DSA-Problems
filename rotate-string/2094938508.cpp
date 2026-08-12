class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == goal[0]){
                for (int j = 0; j < n; j++) {
                    if (goal[j] != s[(i + j) % n]) {
                        break;
                    }
                    count++;
                }
                if(count == n){
                    return true;
                }
                count = 0;
            }
        }
        return false;
    }
};