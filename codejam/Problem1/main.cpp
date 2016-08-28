#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

#include <set>
#include <map>

#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, const char* argv[]) {
    //string inpath = argv[1];
    //string outpath = argv[2];

    string inpath  = "/Users/qiaotian/Downloads/A-small-attempt0.in.txt";
    string outpath = "/Users/qiaotian/Downloads/A-small-attempt0.out.txt";

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
        int ll, rr;
        getline(infile, currline);
        istringstream iss(currline);
        iss >> ll >> rr;

        //vector<string> names;
        vector<pair<string, int>> count; // name to count

        int ans = (min(ll, rr)+1)*min(ll, rr)/2;

        outfile << "Case #" << i+1 <<": " << ans << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
