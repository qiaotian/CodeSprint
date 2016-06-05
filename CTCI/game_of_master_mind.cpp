/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-05T22:40:02+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-05T23:24:26+08:00
* @License: DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
*/

/**
The Game of Master Mind is played as follows:
The computer has four slots containing balls that are red(R), yellow(Y), green(G) or blue(B). For example. the computer might have RGGB(e.g., Slot  #1 is red, Slot #2 and Slot #3 are green, Slot #4 is blue.

You ,the user, are trying to guess the solution. You might, for example, guess YRGB.

When you guess the correct color for the correct slot, you get a "hit". If you guess a color that exists but is in the wrong slot, you get a "pseudo-hit". For example, the guess YRGB has 2 hits and one pseudo hit.

For each guess, you are told the number of hits and pseudo-hits.

Write a method that, given a guess and a solution, returns the numnber of hits and pseudo hits.
*/

enum COLOR{ R, Y, G, B};

class Result{
    int hit;
    int pesudo;
    Result(int x, int y) {
        hit = x;
        pesudo = y;
    }
};

class Solution{
private:
    vector<COLOR> parse(string guess) {
        vector<COLOR> ans;
        for(auto i:guess) {
            if(i=='R') ans.push_back(R);
            else if(i=='Y') ans.push_back(Y);
            else if(i=='G') ans.push_back(G);
            else ans.push_back(B);
        }
        return ans;
    }
public:
    Result game_of_master_mind(string guess, string solution) {
        Result res(0, 0);
        int solution_mask = 0;
        // hash the color onto bit of a integer
        for(int i=0; i<4; i++) {
            solution_mask |= 1<<(1+solution[i]-'A');
        }
        //
        for(int i=0; i<4; i++) {
            if(guess[i]==solution[i]){
                res.hit++;
            } else {
                if(solution_mask & (1<<(1+guess[i]-'A')) >= 1) {
                    ++ res.peudo++;
                }
            }
        }
        return res;
        /*
        vector<COLOR>& gue = parse(guess);
        vector<COLOR>& sln = parse(solution);
        for(int i=0; i<4; i++) {
            if(gue[i]==sln[i]) {
                res.hit++;
                continue;
            }
            for(int j=0; j<4; j++) {
                if(j==i) continue;
                if(gue[i]==sln[j]) {
                    res.pesudo++;
                    break;
                }
            }
        }
        */

    }
};

// The answer(s) might not containing just one soluton
// The game just inlcudes only have 256(4^4) kinds of solutions
// Test every possible solution to find out the correct one(s)
