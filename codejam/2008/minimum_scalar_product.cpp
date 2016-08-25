/*
Problem A. Minimum Scalar Product
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.

Small input
5 points
Solve A-small
Large input
10 points
Solve A-large
Problemem

You are given two vectors v1=(x1,x2,...,xn) and v2=(y1,y2,...,yn). The scalar product of these vectors is a single number, calculated as x1y1+x2y2+...+xnyn.

Suppose you are allowed to permute the coordinates of each vector as you wish. Choose two permutations such that the scalar product of your two new vectors is the smallest possible, and output that minimum scalar product.

Input

The first line of the input file contains integer number T - the number of test cases. For each test case, the first line contains integer number n. The next two lines contain n integers each, giving the coordinates of v1 and v2 respectively.
Output

For each test case, output a line

Case #X: Y
where X is the test case number, starting from 1, and Y is the minimum scalar product of all permutations of the two given vectors.
Limits

Small dataset

T = 1000
1 ≤ n ≤ 8
-1000 ≤ xi, yi ≤ 1000

Large dataset

T = 10
100 ≤ n ≤ 800
-100000 ≤ xi, yi ≤ 100000

Sample


Input

    2
    3
    1 3 -5
    -2 4 1
    5
    1 2 3 4 5
    1 0 1 0 1

Output

    Case #1: -25
    Case #2: 6

 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

long long minimum_scalar_product(vector<int>& vec1, vector<int>& vec2) {
    int n = vec1.size();

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end(), greater<int>());

    long long minval = 0;
    for(int i=0; i<n; i++) minval+=vec1[i]*vec2[i];

    return minval;
}

int main(int argc, const char* argv[]) {
    string ipath = "/Users/qiaotian/Documents/OJ/codejam/2008/A-large-practice.in.txt";
    string opath = "/Users/qiaotian/Documents/OJ/codejam/2008/A-large-practice.out.txt";

    ifstream ifile(ipath);
    ofstream ofile(opath, fstream::out);

    if(!ifile) {
        cout << "open file in failed" << endl;
        return EXIT_FAILURE;
    }

	if(!ofile) {
		cout << "open file out failed" << endl;
		return EXIT_FAILURE;
	}

    int T;
	string line;
    getline(ifile, line);
	istringstream iss(line);
	iss >> T;
    vector<int> vec1;
    vector<int> vec2;

    for(int i=0; i<T; i++) {
        int n;
        getline(ifile, line);
		iss.clear();
		iss.str(line);

		iss >> n;

        vec1.clear();
        vec2.clear();

		getline(ifile, line);
		iss.clear();
		iss.str(line);
        for(int j=0; j<n; j++) {
            int tmp;
            iss >> tmp;
            vec1.push_back(tmp);
        }
		getline(ifile, line);
		iss.clear();//多次改变iss一定要clear
		iss.str(line);
        for(int j=0; j<n; j++) {
            int tmp = 0;
            iss >> tmp;
            vec2.push_back(tmp);
        }

        long long ans = minimum_scalar_product(vec1, vec2);
        ofile << "Case #" << i+1 << ": " << ans <<endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}
