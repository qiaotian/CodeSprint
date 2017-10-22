// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <iostream>

using namespace std;

int solution(int A, int B) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> numA;
    vector<int> numB;
    if(A) {
        while(A) {
            numA.push_back(A%10);
            A/=10;
        }
    } else {
        numA.push_back(0);
    }
    if(B) {
        while(B) {
            numB.push_back(B%10);
            B/=10;
        }
    } else {
        numB.push_back(0);
    }
    bool isa = true;
    int ans = 0;
    while(!numA.empty() || !numB.empty()) {
        if(isa) {
            if(!numA.empty()) {
                ans = ans*10 + numA.back();
                numA.pop_back();
            }
            isa = false;
        } else {
            if(!numB.empty()) {
                ans = ans*10 + numB.back();
                numB.pop_back();
            }
            isa = true;
        }
        if(ans > 100000000) return -1;
    }
    return ans;
}

int main() {
    cout << solution(0, 1234) << endl;
    return 0;
}
