#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

#include <set>
#include <map>

#include <unordered_map>
#include <unordered_set>

#include <iomanip>


using namespace std;

double solvefunction(vector<int>& costs) {
    int n = costs.size();
    double ll = -1.0;
    double rr = 1.0;

    while(ll<rr) {
        double mm = (ll + rr) / 2;

        double ans  = 0.0;
        double ansl = 0.0;
        double ansr = 0.0;
        for (int i = 0; i < n; i++) {
            ans  += ((i == 0) ? -1 : 1) * costs[i] * pow(1 + mm, n - 1 - i);
            ansl += ((i == 0) ? -1 : 1) * costs[i] * pow(1 + ll, n - 1 - i);
            ansr += ((i == 0) ? -1 : 1) * costs[i] * pow(1 + rr, n - 1 - i);
        }



        if(abs(ans)<=0.000000000001 || rr-ll<=0.000000000001) return mm;

        if ((ans > 0.0000000000001 && ansr > 0.0000000000001)||(ans < -0.0000000000001 && ansr < -0.0000000000001)) rr = mm;
        else ll = mm;
    }
}

int main(int argc, const char* argv[]) {
    //string inpath = argv[1];
    //string outpath = argv[2];

    string inpath  = "/Users/qiaotian/Downloads/C-large.in.txt";
    string outpath = "/Users/qiaotian/Desktop/Problem2/C-large.out.txt";

    ifstream infile(inpath);
    ofstream outfile(outpath);

    if(!infile || !outfile) {
        cout << "open files failed" << endl;
        return EXIT_FAILURE;
    }

    int num_cases = 0; // test case number
    string currline;

    //vector<vector<int> > tests;

    //infile >> num_cases; 这样使用会造成getline(infile)的第一行为空
    getline(infile, currline);
    num_cases = stoi(currline);


    for(int i=0; i<num_cases; i++) {
        //
        int M;
        getline(infile, currline);
        istringstream iss(currline);
        iss>>M;

        vector<int> C;

        // fill C
        //for(int j=0; j<M+1; j++) {
            getline(infile, currline);
            istringstream iss2(currline);
            while (!iss2.eof()) {
                int cost;
                iss2 >> cost;
                C.push_back(cost);
            }
        //}

        double ans = solvefunction(C);

        // output the result
        outfile << "Case #" << i+1 <<": " << setiosflags(ios::fixed) << setprecision(12) << ans << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}