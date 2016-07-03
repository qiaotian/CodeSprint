/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-03T00:26:14+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-03T00:27:05+08:00
* @License: Free License
* @Amazon: Amazon, VMWare
*/

/**
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:
[3 4 1 4 1]
Sample Output:
1
*/


int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    /* MLE;
    unordered_set<int> dict;
    for(auto i:A) {
        if(dict.find(i) != dict.end()) return i;
        else dict.insert(i);
    }
    return -1;
    */

    /* A为const不能修改
    int n = A.size();
    for(int i=0; i<n; i++) {
        if(A[A[i]-1] != A[i]) {
            swap(A[A[i]-1], A[i]);
        }
        if(A[A[i]-1] == A[i] && A[i]-1 != i) {
            return A[i];
        }
    }
    return -1;
    */

        if (A.size() <= 1) return -1;
        int valueRange = A.size() - 1; // 1 to N when the size is N+1.
        int range = sqrt(valueRange);
        if (range * range < valueRange) range++;
        int count[range + 1];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < A.size(); i++) {
        count[(A[i] - 1) / range]++;
        }

        int repeatingRange = -1;
        int numRanges = ((valueRange - 1) / range) + 1;
        for (int i = 0; i < numRanges && repeatingRange == -1; i++) {
            if (i < numRanges - 1 || valueRange % range == 0) {
                if (count[i] > range) repeatingRange = i;
            } else {
                if (count[i] > valueRange % range) repeatingRange = i;
            }
        }
        if (repeatingRange == -1) return -1;
        memset(count, 0, sizeof(count));
        for (int i = 0; i < A.size(); i++) {
            if ((A[i] - 1) / range == repeatingRange) count[(A[i] - 1) % range]++;
        }
        for (int i = 0; i < range; i++) {
            if (count[i] > 1) {
                return repeatingRange * range + i + 1;
            }
        }
        return -1;
};
// 元素可以重复2遍甚至更多
// 重复元素可以有2个或者更多

// Hint:
// Note that summing up the numbers or XOR of the numbers is not going to work in this case.
// Can you try solving the problem in sqrt(n) space?
// Split the numbers from 1 to n in sqrt(n) ranges so that range i
// corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).

// Split the numbers from 1 to n in sqrt(n) ranges so that range i corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).
// Do one pass through the stream of numbers and figure out how many numbers fall in each of the ranges.
// At least one of the ranges will contain more than sqrt(n) elements.
// Do another pass and process just those elements in the oversubscribed range.
// Using a hash table to keep frequencies, you’ll find a repeated element.
// This is O(sqrt(n)) memory and 2 sequential passes through the stream.
