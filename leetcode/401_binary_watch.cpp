/*
 binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/

// 语法错误类型：
// Line 5: expected identifier before numeric constant
// 将vector构造放在函数外
// Line 24: invalid types '<unresolved overloaded function type>[int]' for array subscript
// 将参数外的方框写成小括号造成的

// 注意，在类中方法外不能使用vector<int> a(k, x)的形式
//       需要先申明vector<int> a，然后再构造函数中初始化，
//       或者以 vector<int> a = vector<int>(5) 的形式赋值

class Solution {
private:
    // hours[i]代表i个1可以表示的小时数
    // hours[4]代表大于等于4个1能够表示的小时数，显然为无效
    // vector< vector<int> > hours(4, vector<int>(1, 0)); 
    // vector< vector<int> > minites(6, vector<int>(1, 0));
    vector< vector<int> > hours = vector< vector<int> >(4, vector<int>());
    vector< vector<int> > minites = vector< vector<int> >(6, vector<int>());
public:
    int ones(int n) {
        // 统计n中1的个数
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(n%2) return 1+ones(n>>1);
        else return ones(n>>1);
    }
    void initHoursMinites() {
        for(int i=0; i<12; i++) {
            int tmp = ones(i);
            hours[tmp].push_back(i);
        }
        for(int i=0; i<60; i++) {
            int tmp = ones(i);
            minites[tmp].push_back(i);
        }
    }
    vector<string> readBinaryWatch(int num) {

        vector<string> ans;
        unordered_set<string> uset;
        if(num < 0 || num>8) return ans; //超过8个1，无合法时间，表示11:59只需要8个1

        initHoursMinites();
        
        for(int l=0, r=num; l<=num; l++, r--) {
            if(l>3 || r>5) continue;
            for(int i=0; i<hours[l].size(); i++) {
                for(int j=0; j<minites[r].size(); j++) {
                    string tmp = to_string(hours[l][i])+":"+ (minites[r][j]<10?"0":"") +to_string(minites[r][j]);
                    uset.insert(tmp);
                }
            }
        }
        for(auto t:uset) ans.push_back(t);
        return ans;
    }
};

// 上述统计1个数的算法的标准写法为

int bitCount(int n) {
	int cnt = 0;
	while(n) {
		n = n&(n-1);
		cnt++;
	}
	return cnt;:w
}
