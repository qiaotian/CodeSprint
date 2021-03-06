/**
* @Author: Tian Qiao
* @Date:   2016-07-04T18:44:03+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-05T14:01:43+08:00
* @Inc: Google
* @Difficulty: Medium
* @Tag: Backtracking
*/



_______________________________________________________________________________

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

_______________________________________________________________________________

class Solution {
public:
    bool canWin(string s) {
        if(s.size() == 0) return false;
        for(int i=0; i < s.size()-1; ++i) {
            if(s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                if(!canWin(s)) return true;
                s[i] = '+';
                s[i+1] = '+';
            }
        }
        return false;
    }
};
