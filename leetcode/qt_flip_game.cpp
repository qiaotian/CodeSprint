/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-03T11:20:22+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-03T11:27:31+08:00
* @License: Free License
* @Inc: Google
* @Easy
*/

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
Write a function to compute all possible states of the string after one valid move.
For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]
If there is no valid move, return an empty list [].

________________________________________________________________________________

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        int n = s.size();
        for(int i=0; i<n-1; i++) { // 这里如果写成i<s.size()-1,且当s为空串时会报错
            if(s[i]=='+' && s[i+1]=='+') {
                s[i] = '-';
                s[i+1] = '-';
                ans.push_back(s);
                s[i] = '+';
                s[i+1] = '+';
            }
        }
        return ans;
    }
};
