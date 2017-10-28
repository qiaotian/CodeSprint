/**
 * @Author: qiao
 * @Date:   2017-08-14T21:13:49+08:00
 * @Email:  qiaotian@me.com
 * @Last modified by:   qiao
 * @Last modified time: 2017-08-14T22:23:30+08:00
 * @License: MIT
 * @Copyright: qiaotian
 */


/*
 * DESCRIPTION:
 * A classroom consist of n desks placed in a row, labled from 0 to n-1. Now a exam will held in this classroom. For preventing cheating during exam as harsh as possible, the invigilator will put the student as far to others as he(she) can when a new student comes. The ties can be resolved by seating the left one. Design two functions add_student and rm_student(), where the former one takes the student id as input, then output the seat index, the later one takes the student id as input and return void.
 * Tags: amazon, phone interview, sde3
 */

#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<int, int> seat; // map the student id to seat index

auto cmp = [](pair<int, int> l, pair<int, int> r) { return l.second > r.second || l.first <=r.first;};
priority_queue<pair<int, int>, cmp> room; // start, len, comparison

int add_student(int student_id){
    if(room.empty()) return -1; // have no room left
    pair<int, int> tmp = room.top();
    start = tmp[0]
    len = tmp[1]
    if (start == 0) {
        seat[student_id] = 0;
        room.push(make_pair(1, len-1))
        return 0;
    } else if(start + len >= n) {
        seat[student_id] = n-1;
        room.push(make_pair(start, len-1))
        return n-1;
    } else {
        pos = start + (len-1)/2
        seat[student_id] = pos
        if (len > 1) {
            room.push(make_pair<start, pos-start>)
            room.push(make_pair<pos+1, start+len-pos-1>)
        }
        return pos;
    }

}

void rm_student(int student_id){

}

int main() {
    room.push(make_pair(0,n));

    add_student(1)
    add_student(2)
    add_student(3)
    add_student(4)
    add_student(5)
    add_student(6)

    rm_student(3)
    rm_student(2)
    rm_student(1)
    rm_student(4)
    rm_student(5)
    rm_student(6)

    return 0;
}
