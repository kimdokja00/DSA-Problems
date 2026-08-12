class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs[0].length();
        string small = strs[0];
        string large = strs[strs.size()-1];
        for (int i = 0; i < n; i++) {
            if(small[i]!=large[i]){
                return small.substr(0,i); //here i is not index but length from 0
            }
        }
        return small;
    }
};