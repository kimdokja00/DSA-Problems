class Solution {
public:
    string frequencySort(string s) {
        vector<int> hash(256, 0);
        string result;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            hash[(unsigned char)s[i]]++;
        }
        for (int i = 0; i < n; i++){
            auto maxl = max_element(hash.begin(), hash.end());
            int index = distance(hash.begin(), maxl);
            if(hash[index]==0){
                break;
            }
            int count = hash[index];
            for (int j = 0; j < count; j++) {
                result.push_back((char)index); 
            }
            hash[index]=0;

        }
        return result;
    }
};