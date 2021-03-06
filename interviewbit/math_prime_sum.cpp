/*

Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
NOTE A solution will always exist. read Goldbach’s conjecture

Example:
Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d]

If a < c OR a==c AND b < d.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 1. solution one
bool isPrime(int num) {
	bool ans = false;
	if(num<2) return false;
	int factor = sqrt(num);
    for(int i=2; i<=factor; i++){
        if(num%i==0) return false;
    }
    return true;
}

vector<int> primesum2(int A) {
	vector<int> ans;
    int u = A/2;

    for(int i=2; i<=u; i++){
        if(isPrime(i) && isPrime(A-i)) {
            ans.push_back(i);
            ans.push_back(A-i);
            break;
        }
    }
	return ans;
}

// 2. solution two
vector<int> primesum(int A) {
    vector<int> ans;
    vector<bool> flag(A+1, false);
    flag[2] = true;
    flag[3] = true;
    for(int i=4; i<A+1; i++) {
        int tmp = sqrt(i);
        int j=2;
        for( ; j<=tmp; j++) {
            if(i%j==0) break;
            else {
                if(j==tmp) flag[i] = true;
            }
        }
        //if(j==tmp && i%j!=0) flag[i] = true;
    }
    for(int i=2; i<=(A+1)/2; i++) {
        if(flag[i] && flag[A-i]) {
            ans.push_back(i);
            ans.push_back(A-i);
            break;
        }
    }
    return ans;
}

// 3. solution three
class Solution {
    public:
    vector<int> primesum(int N) {
        
        // Generate isPrime List less equal than N
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        // Sieve of Erastothenes
        for(int i = 2; i <= N; i++) {
            if (!isPrime[i]) continue;
            if (i > N / i) break;
            for (int j = i * i; j <= N; j += i) isPrime[j] = false;
        }
        
        for(int i = 2; i <= N; ++i) {
            if(isPrime[i] && isPrime[N - i]) {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(N - i);
                return ans;
            }
        } 
        
        vector<int> ans; 
        return ans;
    }
};

int main(void) {
	int test = 0;
    cin >> test;
    //vector<int> ans = primesum(test);
    vector<int> ans = primesum2(test);
    for(auto num:ans) cout << num << " " << endl;
	return 0;
}
