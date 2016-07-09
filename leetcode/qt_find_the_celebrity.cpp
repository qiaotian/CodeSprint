/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-10T00:33:55+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-10T01:30:00+08:00
* @Inc: LinkedIn, FB
*/


/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
*/


// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n==0 || n==1) return -1;

        int count = n; // 初始化待定人员数目
        vector<int> flag;

        for(int i=0; i<n; i++) flag.push_back(i);

        while(count>1) {
            int tmp = count;
            for(int i=0; i<tmp/2; i++) {
                if(knows(flag[2*i], flag[2*i+1])) {
                    flag[i] = flag[2*i+1];
                } else {
                    flag[i] = flag[2*i];
                }
                count--;
            }
            if(tmp%2) flag[tmp/2] = flag[tmp-1];
        }

        for(int i=0; i<n; i++) {
            if(i==flag[0]) continue;
            if(!knows(i, flag[0]) || knows(flag[0], i)) return -1;
        }
        return flag[0];
    }
};// Forward declaration of the knows API.


// shorter
// Forward declaration of the knows API.
bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
        if(n<=1) return n;
        int candidate = 0;
        for(int i=1; i<n; i++){
            if (!knows(i,candidate)) candidate = i;
        }
        for(int j=0; j<n; j++) {
            if(j== candidate) continue;
            if(!knows(j,candidate) || knows(candidate,j))return -1;
        }
        return candidate;
    }
};
