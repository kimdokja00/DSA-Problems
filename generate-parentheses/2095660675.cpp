class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string ex = string(n, '(') + string(n, ')');
        do{
            int balance = 0;
            bool isValid = true;

            for (char ch : ex) {
                if (ch == '(') {
                    balance++;
                } else {
                    balance--;
                }
                if (balance < 0) {
                    isValid = false;
                    break;
                }
            }
            if (isValid && balance == 0) {
                result.push_back(ex);
            }
        }
        while (next_permutation(ex.begin(), ex.end()));
        
        return result;
    }
};