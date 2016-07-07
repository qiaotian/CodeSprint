/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-07T21:27:02+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-07T23:46:26+08:00
*/



Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:
a = 2
b = [3]
Result: 8

Example2:
a = 2
b = [1,0]
Result: 1024


/* TLE 每次b除以2都生成新的vector
class Solution {
public:
    vector<int> divide(vector<int>& b) {
        vector<int> ans;
        int remain = 0;
        for(int i=0; i<b.size(); i++) {
            int digit = (remain*10+b[i])/2;
            remain = (remain*10+b[i])%2;
            if(digit==0 && i==0) continue;
            ans.push_back(digit);
        }
        for(auto i:ans) cout << i << " ";
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(b.size()==1 && b[0]==1) return a%1337;

        int l = (b.back()%2?a:1)%1337;
        vector<int> half_b = divide(b);
        int r = (int)pow(superPow(a, half_b)%1337, 2) % 1337;
        return l*r%1337;
    }
};*/

/* TLE 改进：将b/2的结果保存在b内
class Solution {
public:
    void half(vector<int>& b, int& pos) {
        int remain = 0;
        for(int i=pos; i<b.size(); i++) {
            int digit = (remain*10+b[i])/2;
            remain = (remain*10+b[i])%2;
            b[i]=digit;

            if(pos == b.size()-1) break;

            if(i==pos && digit==0) {
                pos++;
                continue;
            }
        }
    }

    int util(int a, vector<int>& b, int pos) {
        if(pos==b.size()-1 && b.back()==1) return a%1337;
        int low = (b.back()%2?a:1)%1337;
        half(b, pos);
        int high = (int)pow(util(a, b, pos), 2) %1337;
        return low*high%1337;
    }
    int superPow(int a, vector<int>& b) {
        return util(a, b, 0);
    }
};*/

// 上述时间复杂度为Nlog2N, 本方法复杂度为NlgN
class Solution {
public:
 long long myPow(long long num, int k) {
   if (k == 0) return 1;
   if (k == 1) return (num % 1337);

   return (myPow(num % 1337, k / 2) % 1337) * (myPow(num % 1337, k - k / 2) % 1337) % 1337;
 }

 int superPow(int a, vector<int>& b) {
   int n = b.size();
   long long ret = 1;
   for (int i = 0; i < n; i++) {
     ret = (long long)(myPow(ret, 10) * (long long)myPow(a, b[i])) % 1337;
   }
   return ret;
 }
};
