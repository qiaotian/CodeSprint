#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string ipath = "/Users/qiaotian/Desktop/RoundC/i.txt";
    string opath = "/Users/qiaotian/Desktop/RoundC/o.txt";

    ifstream ifile(ipath);
    ofstream ofile(opath);

    if(!ifile) {
        cout << "open input file failed" << endl;
        return EXIT_FAILURE;
    }

    if(!ofile) {
        cout << "open output file failed" << endl;
        return EXIT_FAILURE;
    }

    int cnt = 0;
    string line;
    vector<string> ans;

    getline(ifile, line);
    cnt = stoi(line);
    for(int i=0; i<cnt; i++) {
        getline(ifile, line);
        istringstream iss(line);
        while (!iss.eof()) {
            //string tmp;
            //iss >> tmp;
            //strs.push_back(tmp);
        }

        ofile << "Case #" << i+1 <<":";
        //for(int j = 0; j<strs.size(); j++) {
        //    ofile << " " << strs[strs.size()-j-1];
        //}
        ofile << endl;
    }
    ifile.close();
    ofile.close();
    return 0;
}
