class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string res = digits;
        vector<vector<char>> car(res.length());
        string result;
        vector<string> ret;
        int a = 1;
        int n = res.length();
        for (int i = 0; i < res.length(); i++) {
            switch (res[i]) {

            case '2':
                car[i].push_back('a');
                car[i].push_back('b');
                car[i].push_back('c');
                a = a * 3;
                break;
            case '3':
                car[i].push_back('d');
                car[i].push_back('e');
                car[i].push_back('f');
                a = a * 3;
                break;
            case '4':
                car[i].push_back('g');
                car[i].push_back('h');
                car[i].push_back('i');
                a = a * 3;
                break;
            case '5':
                car[i].push_back('j');
                car[i].push_back('k');
                car[i].push_back('l');
                a = a * 3;
                break;

            case '6':
                car[i].push_back('m');
                car[i].push_back('n');
                car[i].push_back('o');
                a = a * 3;
                break;

            case '7':
                car[i].push_back('p');
                car[i].push_back('q');
                car[i].push_back('r');
                car[i].push_back('s');
                a = a * 4;
                break;

            case '8':
                car[i].push_back('t');
                car[i].push_back('u');
                car[i].push_back('v');
                a = a * 3;
                break;

            case '9':
                car[i].push_back('w');
                car[i].push_back('x');
                car[i].push_back('y');
                car[i].push_back('z');
                a = a * 4;
                break;
            }
        }
        for (int j = 0; j < a; j++) {
            int div = a ;
            for (int k = 0; k < digits.length(); k++) {
                div = div / car[k].size();
                int index = (j / div) % car[k].size();
                result.push_back(car[k][index]);
            }
            
            ret.push_back(result);
            result = "";
        }
        return ret;
    }
};