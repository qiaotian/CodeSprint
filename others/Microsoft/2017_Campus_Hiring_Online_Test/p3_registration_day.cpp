/*
Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
It's H University's Registration Day for new students. There are M offices in H University, numbered from 1 to M. Students need to visit some of them in a certain order to finish their registration procedures. The offices are in different places. So it takes K units of time to move from one office to another.

There is only one teacher in each office. It takes him/her some time to finish one student's procedure. For different students this time may vary. At the same time the teacher can only serve one student so some students may need to wait outside until the teacher is available. Students who arrived at the office earlier will be served earlier. If multiple students arrived at the same time they will be served in ascending order by student number.

N new students need to finish his/her registration. They are numbered from 1 to N. The ith student's student number is Si. He will be arrived at H University's gate at time Ti. He needs to visit Pi offices in sequence which are Oi,1, Oi,2, ... Oi,Pi. It takes him Wi,1, Wi,2, ... Wi,Pi units of time to finish the procedure in respective offices. It also takes him K units of time to move from the gate to the first office.

For each student can you tell when his registration will be finished?

Input
The first line contains 3 integers, N, M and K.  (1 <= N <= 10000, 1 <= M <= 100, 1 <= K <= 1000)

The following N lines each describe a student.

For each line the first three integers are Si, Ti and Pi. Then following Pi pairs of integers: Oi,1, Wi,1, Oi,2, Wi,2, ... Oi,Pi, Wi,Pi. (1 <= Si <= 2000000000, 1 <= Ti <= 10000, 1 <= Pi <= M, 1 <= Oi,j <= M, 1 <= Wi,j <= 1000)

Output
For each student output the time when he finished the registration.

Sample Hint
Student 1600012345 will be arrived at the gate at time 500. He needs to first visit Office #1 and then Office #2. He will be arrived at office #1 at time 600. He will leave office #1 at time 1100. Then He will arrive at office #2 at 1200. At the same time another student arrives at the same office too. His student number is smaller so he will be served first. He leaves Office #2 at 1700. End of registration.

Student 1600054321 will be arrived at the gate at time 1100. He will be arrived at Office #2 at 1200. Another student with smaller student number will be served first so he waits for his turn until 1700. He leaves Office #2 at 2000. End of registration.

Sample Input
2 2 100
1600012345 500 2 1 500 2 500
1600054321 1100 1 2 300
Sample Output
1700
2000
*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define PB          push_back
#define MP(x,y)     make_pair(x,y)
#define CLR(x,y)    memset(x, y, sizeof(x))
#define FOR(i,n,m)  for(int i=n; i<=m; i++)
#define ROF(i,n,m)  for(int i=n; i>=m; i--)

#define RI(x)       scanf("%d", &(x))
#define RII(x,y)    RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

struct Student {
    int id;
    int student_num;
    int arrive_time;
    queue<pair<int, int>> tasks; //注册流程
    Student(){
        arrive_time = 0;
    }
    Student(int _id, int _student_number, int _arrive_time): id(_id), student_number(_student_number) arrive_time(_arrive_time){}
    bool operator < (const node &A) const {
        if(arrive_time == A.arrive_time) return student_num > A.student_num;
        return arrive_time > A.arrive_time;
    }
};

// 学生每完成一项任务，要么该学生完成所有流程，要么进入下一个队列参与排队
int main() {
    int N, M, K; // student number, office number, time expense between any two offices
    //cin >> N >> M >> K;
    RIII(N,M,K);
    //vector<queue<int>> TaskQueues(M, queue<int>()); // 队列中按服务先后存放学生id
    priority_queue<Student> Q;
    vector<int> finish_time(N, 0);
    //for(int i=0; i<N; i++) {
    FOR(i,0,N-1) {
        Student student;
        //cin >> student.id >> student.arrive_time >> student.tasks_num;
        RIII(student.student_num, student.arrive_time, student.tasks.size()-1);

        //for(int j=0; j<student.tasks_num; j++) {
        FOR(j,0,student.tasks.size()-1) {
            int o, w;
            //cin >> o >> w;
            RII(o,w);
            student.tasks.push({o, w});
        }
        //students.push_back(student);
        students.PB(student);
        Q.push(student);
    }

    while(!Q.empty()) {
        student cur = Q.front();
        Q.pop();

        pair<int,int> job = cur.tasks.front();
        cur.tasks.pop();
        cur.arrive_time = cur.arrive_time+job.second+K;
        if(cur.tasks.empty()) {
            finish_time[cur.id] = cur.arrive_time-K;
        } else {
            Q.push(cur);
        }
    }

    for(auto t:finish_time) cout << t << endl;
    return 0;
}
