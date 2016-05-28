#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream> // string based parsing

using namespace std;

/**
Other than using getline, we could also use seekg() to solve this
problem. But, seekg need to load the entire file into mem, which cost
too much in space if the file is large.
**/

int main(int argc, const char* argv[]) {
    //cout << argc << endl;
    //cout << argv[0] << endl;
    //cout << argv[1] << endl;
    //cout << argv[2] << endl;

    int K = stoi(argv[1]); // the number of lines need to be printed
    string fpath = argv[2];
    ifstream infile(fpath);
    if(!infile) {
        cout << "Open file failure!" << endl;
        return EXIT_FAILURE;
    }

    int num = 0;
    string line;
    vector<string> lines(K);
    while(std::getline(infile, line)) {
        lines[num%K] = line;
        num++;
    }

    // print all numbers if less than K lines were read
    int start = 0;
    int count = 0;
    if(num < K) {
        start = 0;
        count = num;
    } else {
        start = num%K;
        count = K;
    }

    for(int i = 0; i < count; ++i) {
        cout << lines[(start+i)%K] << endl;
    }
    /** or
    for(string line; getline(infile, line); ) {
        // for each line
    }

    */
}
