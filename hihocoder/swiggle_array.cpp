/*

Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB

Description
给定一个长度为N的数组A1, A2, ..., AN，如果对于任意1 < i < N都有Ai > Ai-1且Ai > Ai+1, 或者Ai < Ai-1且Ai < Ai+1，我们就称A数组是一个震荡数组。
例如{4, 2, 3, 1, 5}就是一个震荡数组；而{1, 4, 3, 2, 5}不是一个震荡数组因为4, 3, 2三个连续的元素不满足条件。
现在给定一个长度为N的数组组A1, A2, ..., AN，最少进行多少次两两交换，可以使A变成一个震荡数组？

Input
第一行包含一个整数N，代表数组的长度。(1 <= N < 30)
第二行包含N个整数，A1, A2, ... AN。 (1 <= Ai <= N)
输入保证Ai两两不同。

Output
输出最少交换的次数。

Sample Input
5
1 2 3 4 5
Sample Output
1

*/


#include <iostream>
#include <vector>

int min_swap(vector<int>& nums) {
	int n = nums.size();
	
}
