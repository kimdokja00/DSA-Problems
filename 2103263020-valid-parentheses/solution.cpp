class Solution {
public:
    bool isValid(string s) {//optimal but some mirror fixes
        stack<char> brack;
        int n = 0;
        while (n < s.length()) {
            char ch = s[n];
            if (ch == '(' || ch == '{' || ch == '[') {
                brack.push(ch);
            } else {
                 if (brack.empty()) {
                    return false;
                }

                if (brack.top() == '(' && ch == ')') {
                    brack.pop();
                } else if (brack.top() == '{' && ch == '}') {
                    brack.pop();
                } else if (brack.top() == '[' && ch == ']') {
                    brack.pop();
                } else {
                    return false;
                }
            }
            n++;
        }
        if (brack.empty()) {
            return true;
        }
        return false;
    }
};