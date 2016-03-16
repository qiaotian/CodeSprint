#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, const char* argv[]) {
    string inpath = argv[1];
    string outpath = argv[2];
    //string inpath = "/Users/qiaotian/Desktop/TEST/TEST/B-small-practice.in.txt";
    //string outpath = "/Users/qiaotian/Desktop/TEST/TEST/B-small-practice.out.txt";

    ifstream infile(inpath);
    ofstream outfile(outpath);
    if(!infile || !outfile) {
        cout << "open files failed" << endl;
        return EXIT_FAILURE;
    }

    int num_cases = 0;
    string currline;

    //infile >> num_cases; 这样使用会造成getline(infile)的第一行为空
    getline(infile, currline);
    num_cases = stoi(currline);
    vector<string> strs;
    for(int i = 0; i<num_cases; i++) {
        strs.clear();
        // read a line put words into vector
        getline(infile, currline);
        istringstream iss(currline);
        while (!iss.eof()) {
            string tmp;
            iss >> tmp;
            strs.push_back(tmp);
        }

        // revert vector
        outfile << "Case #" << i+1 <<":";
        for(int j = 0; j<strs.size(); j++) {
            outfile << " " << strs[strs.size()-j-1];
        }
        outfile << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
