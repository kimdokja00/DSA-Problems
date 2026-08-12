class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       int count1 = 0;
        std::vector<int> zero_blocks;
        
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                count1++;
                i++;
            } else {
                int start = i;
                while (i < n && s[i] == '0') {
                    i++;
                }
                zero_blocks.push_back(i - start);
            }
        }
        
        int max_trade_gain = 0;
        for (size_t k = 0; k + 1 < zero_blocks.size(); ++k) {
            max_trade_gain = std::max(max_trade_gain, zero_blocks[k] + zero_blocks[k + 1]);
        }
        
        return count1 + max_trade_gain; 
    }
};