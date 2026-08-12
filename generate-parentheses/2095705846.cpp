class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string ex = string(n, '(') + string(n, ')');
        do {
            int balance = 0;
            bool isValid = true;

            for (char ch : ex) {
                balance += (ch == '(') ? 1 : -1;
                if (balance < 0) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(ex);
            }
        } while (next_permutation(ex.begin(), ex.end()));

        return result;
    }
};