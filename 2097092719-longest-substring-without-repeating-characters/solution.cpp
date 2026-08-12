class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string result;
        int maxlen = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int pos = result.find(s[i]);
            if (pos != string::npos) {
                result.erase(0, pos  + 1);
            }
            result.push_back(s[i]);
            maxlen = max<int>(result.length(), maxlen);
        }

        return maxlen;
    }
};