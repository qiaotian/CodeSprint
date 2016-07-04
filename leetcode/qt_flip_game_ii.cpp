/**
* @Author: Tian Qiao
* @Date:   2016-07-04T18:44:03+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-04T18:58:10+08:00
* @Inc: Google
* @Difficulty: Medium
* @Tag: Backtracking
*/



/*_____________________________________________________________________________

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
_____________________________________________________________________________*/

class Solution {
public:
    bool canWin(string s) {
        int ans = false; // 输
        string buf;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='+') buf+='+';
            else {
                if(buf.size()%4==1) ans^=1;
            }
        }
    }
};
