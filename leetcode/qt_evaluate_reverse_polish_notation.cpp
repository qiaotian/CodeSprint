/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:42:51+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:42:52+08:00
* @Difficulty: Medium
* @Tag: Stack
*/

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> numeric;

        for(auto& t : tokens)
        {
            if (isdigit(t[0]) || t.size()>1)
                numeric.push(atoi(t.c_str()));
            else
            {
                int o1, o2;
                o2 = numeric.top();
                numeric.pop();
                o1 = numeric.top();
                numeric.pop();

                switch(t[0])
                {
                    case '+':
                        numeric.push(o1 + o2);
                        break;
                    case '-':
                        numeric.push(o1 - o2);
                        break;
                    case '*':
                        numeric.push(o1 * o2);
                        break;
                    case '/':
                        numeric.push(o1 / o2);
                        break;
                }
            }
        }

        return numeric.top();
    }
};
