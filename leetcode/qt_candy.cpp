/**
* @Author: Tian Qiao <root>
* @Date:   2016-06-25T10:03:13+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-06-25T11:41:19+08:00
* @License: Free License
*/


/*
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

// my solution
// beats 13%
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<1) return 0;
        if(ratings.size()<2) return 1;
        vector<int> count(ratings.size(), 1);
        vector<int> flags(ratings.size(), false);
        // from left to right
        for(int i=0; i<ratings.size(); i++) {
            if(i==0) {
                if(ratings[i]<=ratings[i+1]) flags[i] = true;
                if(ratings[i]>ratings[i+1] && flags[i+1]) {
                    count[i] = count[i+1]+1;
                    flags[i] = true;
                }
            }
            else if(i==ratings.size()-1) {
                if(ratings[i]<=ratings[i-1]) flags[i] = true;
                if(ratings[i]>ratings[i-1] && flags[i-1]) {
                    count[i] = count[i-1]+1;
                    flags[i] = true;
                }
            } else {
                if(ratings[i]<=ratings[i+1] && ratings[i]<=ratings[i-1]) {
                    flags[i] = true;
                }
                if(ratings[i]>ratings[i-1] && ratings[i] <=ratings[i+1] && flags[i-1]) {
                    count[i] = count[i-1]+1;
                    flags[i] = true;
                }
                if(ratings[i]>ratings[i+1] && ratings[i] <=ratings[i-1] && flags[i+1]) {
                    count[i] = count[i+1]+1;
                    flags[i] = true;
                }
                if(ratings[i]>ratings[i+1] && ratings[i] >ratings[i-1] && flags[i+1] && flags[i-1]) {
                    count[i] = max(count[i-1], count[i+1])+1;
                    flags[i] = true;
                }
            }
        }


        // from right to left
        for(int i=ratings.size()-1; i>=0; i--) {
            if(i==0) {
                if(ratings[i]<=ratings[i+1]) flags[i] = true;
                if(ratings[i]>ratings[i+1] && flags[i+1]) {
                    count[i] = count[i+1]+1;
                    flags[i] = true;
                }
            }
            else if(i==ratings.size()-1) {
                if(ratings[i]<=ratings[i-1]) flags[i] = true;
                if(ratings[i]>ratings[i-1] && flags[i-1]) {
                    count[i] = count[i-1]+1;
                    flags[i] = true;
                }
            } else {
                if(ratings[i]<=ratings[i+1] && ratings[i]<=ratings[i-1]) {
                    flags[i] = true;
                }
                if(ratings[i]>ratings[i-1] && ratings[i] <=ratings[i+1] && flags[i-1]) {
                    count[i] = count[i-1]+1;
                    flags[i] = true;
                }
                if(ratings[i]>ratings[i+1] && ratings[i] <=ratings[i-1] && flags[i+1]) {
                    count[i] = count[i+1]+1;
                    flags[i] = true;
                }
                if(ratings[i]>ratings[i+1] && ratings[i] >ratings[i-1] && flags[i+1] && flags[i-1]) {
                    count[i] = max(count[i-1], count[i+1])+1;
                    flags[i] = true;
                }
            }
        }

        int ans = 0;
        for(auto i:count) ans+=i;
        return ans;
    }
};

// bests 36% (best)
// 该题类似于登上，先从山的阳面登上山顶，忽略阴面，再从山的阴面登上顶，忽略阳面
// 该解法思路一样，却简便许多，化繁为简的能力差距甚多
class Solution {
public:
    int candy(vector<int> &ratings) {
        int size=ratings.size();
        if(size<=1) return size;
        vector<int> num(size,1);
        for (int i = 1; i < size; i++) {
             if(ratings[i]>ratings[i-1])
             num[i]=num[i-1]+1;
        }
        for (int i= size-1; i>0 ; i--) {
            if(ratings[i-1]>ratings[i])
                num[i-1]=max(num[i]+1,num[i-1]);
        }
        int ans=0;
        for (auto i:num) ans+=i;
        return ans;
    }
};
