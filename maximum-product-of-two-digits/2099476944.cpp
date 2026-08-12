class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        vector<int> result;
        for(int i = 0;i < num.length();i++){
            result.push_back(num[i]-'0');
        }
        sort(result.begin(),result.end(),greater<int>());
        return result[0]*result[1];
    }
};