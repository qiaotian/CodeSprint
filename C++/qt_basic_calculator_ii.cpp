// 该题测试用例"1*2*3*4*5*6*7*8*9*10"有bug，无法通过
/*
class Solution {
public:
    int calculate(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '+') return calculate(s.substr(0, i)) + calculate(s.substr(i+1));
            if(s[i] == '-') return calculate(s.substr(0, i)) + calculate(s.substr(i+1));
            if(s[i] == '*' || s[i] == '/') {
                int r1 = i-1;
                while(s[r1] == ' ') r1--;
                int l1 = r1;
                while(isdigit(s[l1])) l1--;
                l1++;
                int lnum = stoi(s.substr(l1, r1-l1+1));
                
                int l2 = i+1;
                while(s[l2] == ' ') l2++;
                int r2 = l2;
                while(isdigit(s[r2])) r2++;
                r2--;
                int rnum = stoi(s.substr(l2, r2-l2+1));
                
                s.replace(l1, r2-l1+1, to_string(s[i] == '*'?lnum*rnum:lnum/rnum));
                
                return calculate(s);
            }
        }
        return stoi(s);
    }
};
*/

// 20ms, beats 69.3%
class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' or op == '-') {
                total += term;
                in >> term;
                term *= 44 - op;
            } else {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
    }
};


