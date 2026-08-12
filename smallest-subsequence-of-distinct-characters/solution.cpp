class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occ(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            last_occ[s[i] - 'a'] = i;
        }
        
        string stack = "";
        vector<bool> seen(26, false);
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            if (seen[c - 'a']) {
                continue;
            }
            
            while (!stack.empty() && c < stack.back() && last_occ[stack.back() - 'a'] > i) {
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            stack.push_back(c);
            seen[c - 'a'] = true;
        }
        
        return stack; 
        }
};