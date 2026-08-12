class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0;i<strs[0].size();i++){
            char ch = strs[0][i];
            for(int j = 1;j<strs.size();j++){
                if(i>strs[j].size() || ch != strs[j][i]){
                    return ans;
                }
                
            }
            ans = strs[0].substr(0,i +1);
        }
        return strs[0];
    }
};