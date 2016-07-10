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

    string inpath  = "/Users/qiaotian/Downloads/test2.txt";
    string outpath = "/Users/qiaotian/Desktop/Problem3/test2.out.txt";

    ifstream infile(inpath);
    ofstream outfile(outpath);

    if(!infile || !outfile) {
        cout << "open files failed" << endl;
        return EXIT_FAILURE;
    }

    int num_cases = 0; // test case number
    string currline;

    //vector<vector<int> > tests;

    getline(infile, currline);
    num_cases = stoi(currline);


    for(int i=0; i<num_cases; i++){
        int M, N;
        //vector<string> names;
        //vector<pair<string, int>> count; // name to count

        getline(infile, currline);
        istringstream iss(currline);
        iss>> M >> N; //  rows and cols

        vector<vector<int>> height(M, vector<int>(N, 0));

        for(int i=0; i<M; i++) {
            getline(infile, currline);
            istringstream iss(currline);
            for(int j=0; j<N; j++) {
                iss >> height[i][j];
            }
        }




        // output the result
        outfile << "Case #" << i+1 <<": " << count[0].first << endl;
    }
    infile.close();
    outfile.close();

    return 0;
}