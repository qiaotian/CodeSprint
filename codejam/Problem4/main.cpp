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

    string inpath  = "/Users/qiaotian/Downloads/test4.txt";
    string outpath = "/Users/qiaotian/Desktop/Problem4/test4.out.txt";

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


    for(int i=0; i<num_cases; i++){
        int M, N;
        //vector<string> names;
        //vector<pair<string, int>> count; // name to count

        getline(infile, currline);
        istringstream iss(currline);
        iss>> M >> N;

        vector<vector<int>> damage()

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