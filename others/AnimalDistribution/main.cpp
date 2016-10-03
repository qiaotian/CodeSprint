#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <regex>

#include "Community.h"

using namespace std;

int main() {
    string fpath = "/Users/qiaotian/Documents/CodeSprint/AnimalDistribution/file.txt";
    ifstream in(fpath);
    stringstream buffer;
    buffer << in.rdbuf();
    string testcase(buffer.str());

    //cout << "++++++++++++++++ INPUT +++++++++++++++++" << endl;
    //cout << testcase << endl;

    Community *comm = new Community();

    string id = "dcfa0c7a-5855-4ed2-bc8c-4accae8bd155";
    int status = comm->process(testcase);

    if(status == DATA_VALIDATE_SUCC) {
        cout << comm->getSnapShot(id) << endl;
    }

    delete comm;
    return 0;
}
