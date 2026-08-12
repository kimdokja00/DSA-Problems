class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        vector<int> res;
        for(int i = 0;i < num.length();i++){
            res.push_back(num[i]-'0');
        }
        sort(res.begin(),res.end(),greater<int>());
        return res[0]*res[1];
    }
};