/*
Time Limit:30000ms
Case Time Limit:2000ms
Memory Limit:1024MB

Description
There are n cities in Byteland (numbered from 1 to n), connected by bidirectional roads. The king of Byteland is not very generous, so there are only n - 1 roads, but they connect the cities in such a way that it is possible to travel from each city to any other city.

The summer vacation is coming, Little Pony is going to have self-driving travelling in Byteland. Start from city 1 with her lovely car, Little Pony want to visit m citys k1, k2, ..., km in any order. When through a edge she can choose whether drive the car(cost c1) or hike(cost c0), she must park her car at a city when she decided to hike. Help Little Pony to manage a visit plan so that to the total cost is minimum.

Note: Little Pony can end at any node, even if without her car.



Input
The first line contains one integer n — the number of the cities in Byteland(1 ≤ n ≤ 10^6).

Each of the next n - 1 lines contains four integers u, v, c0, c1 described a edge as we mention above(1  ≤ u, v ≤ n, 1 ≤ c0, c1 ≤ 10^9).

The next line contains one integer m — the number of the cities that Little Pony want to visit, then the next line contains m distinct integers k1, k2, ..., km(1 ≤ ki ≤ n) — the cities that Little Pony want to visit.



Output
Only one line a single integer as the corresponding result.


Hint
More samples：

Input
7
1 2 10 35
1 5 10 30
2 3 20 10
2 4 20 10
5 6 20 10
5 7 20 10
6
2 3 4 5 6 7
Output
150



Sample Input
4
1 2 10 35
2 3 20 10
2 4 20 10
3
2 3 4
Sample Output
65
*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	vector<vector<int> > path;  //城市之间线路及消耗
	vector<int> visit;  //希望访问的城市编号
	cin >> N;
	for(int i=0; i<N-1; i++) {
		vector<int> one;
		for(int i=0; i<4; i++) {
			int tmp;
			cin >> tmp;
			one.push_back(tmp);
		}
		path.push_back(one);
	}
	cin >> M;
	for(int i=0; i<M; i++) {
		int tmp;
		cin >> tmp;
		visit.push_back(tmp);
	}

	// insert your code here

	return 0;
}
