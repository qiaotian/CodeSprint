/*
团队出游问题
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
有道目前崇尚小团队开发工作,因为团队越小,工作效率越高。团队之间不可避免存在合作,为了把高内聚低耦合的思想用在工作中,每一个团队会有多个跨团队接口人做沟通工作。任何两个团队最多只有一个接口人，一个接口人也只能服务于跨的两个团队,不存在一个人跨三个团队的情况。可能某两个团队工作交流不多，并没有接口人,需要沟通时只能间接沟通(例如团队1与团队2有接口人，团队2和团队3有接口人，则团队1和团队3也可以通过团队2进行间接沟通)。

一年一度的旅游计划就要来了,会按小团队出游，这段时间内，通过这个出游了的团队间接沟通的团队们就只能通过别的第三方团队间接沟通了。需要你帮忙看看,最少有多少团队出去旅游了,会导致某两个小团队处于不能沟通的状态。
输入
第1行是四个由空格分隔的整数：N,M,t1,t2.N是小团队总数(N不会太大，1<=N<=100)，小团队号从1开始。M是接口人总数。t1和t2是两个团队号。
第2行到第M+1行中，每行包括两个团队号，表示这两个团队有1个跨团队接口人。
输出
一个整数，这个整数表示至少有这么多个接口人旅游去了，会导致t1和t2两个团队不能沟通。

样例输入
8 8 1 5
1 2
2 3
3 4
4 5
1 6
6 7
7 8
8 5
样例输出
2
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n, m, t1, t2;
    cin >> n >> m >> t1 > t2;
    for(int i=0; i<n; i++) {
        
    }

    string line;
    while(getline(cin, line)) {
        int n, k;
        istringstream iss(line);
        iss >> n >> k;
        getline(cin, line);
        istringstream iss2(line);
        vector<int> requests(n, 0);
        vector<vector<int>> cenema(k, vector<int>(k, 0)); //0表示空
        for(int i=0; i<n; i++) {
            int tmp;
            iss2 >> tmp;
            requests[i] = tmp;
        }

        for(int i=0; i<n; i++) {
            // 处理request[i]
            int x, yl, yr;
            int tickets = requests[i];


            // 输出
            cout << x << yl << yr << endl;
        }
    }
    return 0;
}
