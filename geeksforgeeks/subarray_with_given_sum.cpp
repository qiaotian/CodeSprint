/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-21T19:57:36+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-21T19:59:12+08:00
* @License: Free License
*/

/**
Given an unsorted array of non-negative integers, find a continous subarray which adds to a given number.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:

Corresponding to each test case, in a new line, print the starting and ending positions of first such occuring subarray if sum equals to subarray, else print -1.

Note: Position of 1st element of the array should be considered as 1.

Expected Time Complexity: O(n)

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ an array element ≤ 200

Example:

Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10

Output:
2 4
1 5

Explanation :
In first test case, sum of elements from 2nd position to 4th position is 12
In second test case, sum of elements from 1st position to 5th position is 15

**For More Examples Use Expected Output**
*/


#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findSum(vector<int>& A, int target) {
    vector<int> sum(A.size(), 0);
    for(int i=0; i<A.size(); i++) {
        if(i==0) sum[i]=A[i];
        else sum[i] = sum[i-1]+A[i];
    }
    for(int i=0; i<sum.size(); i++) {
        int tmp = target+(i==0?0:sum[i-1]);
        //查找tmp
        int ll = i+1;
        int rr = sum.size()-1;
        while(ll<=rr) {
            int mid = (ll+rr)/2;
            if(sum[mid] > tmp) rr = mid-1;
            else if(sum[mid] < tmp) ll = mid+1;
            else return make_pair(i+1, mid+1);// one-based
        }
    }
    return make_pair(INT32_MIN, INT32_MIN);
}

int main() {
	//code
	int samples;
	cin >> samples;
	for(int i=0; i<samples; i++) {
	    int n, target;
	    cin >> n >> target;
	    vector<int> A;
	    for(int j=0; j<n; j++) {
	        int a;
	        cin >> a;
	        A.push_back(a);
	    }
	    pair<int, int> ref = findSum(A, target);
	    if(ref.first == INT32_MIN) cout << -1 << endl;
	    else cout << ref.first << " " << ref.second << endl;
	}
	return 0;
}
