class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string ex = string(n, '(') + string(n, ')');
        do {
            int balance = 0;
            for (char c : ex) {
                if (c == '(')
                    balance++;
                else
                    balance--;
                if (balance < 0)
                    break;
            }
            if (balance == 0) {
                result.push_back(ex);
            }
        } while (next_permutation(ex.begin(), ex.end()));

        return result;
    }
};