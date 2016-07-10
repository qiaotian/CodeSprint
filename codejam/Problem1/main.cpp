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


int countStr(string str) {
    unordered_set<char> s;
    for(auto i:str) {
        if(i!=' ') {
            s.insert(i);
        }
    }
    return s.size();
}

bool cmp(pair<string, int>a, pair<string, int>b) {
    if( a.second > b.second ) return true;
    if( a.second == b.second) {
        return a.first < b.first;
    }
    return false;
}

int main(int argc, const char* argv[]) {
    //string inpath = argv[1];
    //string outpath = argv[2];

    string inpath  = "/Users/qiaotian/Downloads/A-large.in.txt";
    string outpath = "/Users/qiaotian/Desktop/Problem1/A-large.out.txt";

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

        //vector<string> names;
        vector<pair<string, int>> count; // name to count

        int N; // lines
        getline(infile, currline);
        istringstream iss(currline);
        iss>>N;

        for(int i=0; i<N; i++) {
            getline(infile, currline);
            //names.push_back(currline);
            string name = currline;
            int num = countStr(name);
            count.push_back({name, num});
        }

        sort(count.begin(), count.end(), cmp);

        //return count[0].first;


        // output the result
        outfile << "Case #" << i+1 <<": " << count[0].first << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}