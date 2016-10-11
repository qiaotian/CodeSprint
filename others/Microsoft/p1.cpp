/*
Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
There is an integer array A1, A2 ...AN. Each round you may choose two adjacent integers. If their sum is an odd number, the two adjacent integers can be deleted.
Can you work out the minimum length of the final array after elaborate deletions?

Input
The first line contains one integer N, indicating the length of the initial array.

The second line contains N integers, indicating A1, A2 ...AN.
For 30% of the data：1 ≤ N ≤ 10
For 60% of the data：1 ≤ N ≤ 1000
For 100% of the data：1 ≤ N ≤ 1000000, 0 ≤ Ai ≤ 1000000000

Output
One line with an integer indicating the minimum length of the final array.

Sample Hint
(1,2) (3,4) (4,5) are deleted.

Sample Input
7
1 1 2 3 4 4 5
Sample Output
1
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N, 0);

    int odd = 0;
    int eve = 0;

    for(int i=0; i<N; i++) {
        cin >> nums[i];
        if(nums[i]%2) odd++;
        else eve++;
    }

    cout << abs(odd-eve) << endl;

    return 0;
}
