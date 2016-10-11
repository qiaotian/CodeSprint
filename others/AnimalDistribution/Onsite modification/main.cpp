#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <regex>

#include "Community.h"

using namespace std;

int main() {
    string fpath = "/Users/qiaotian/Desktop/AnimalDistribution/file.txt";
    ifstream in(fpath);
    stringstream buffer;
    buffer << in.rdbuf();
    string testcase(buffer.str());

    //cout << "++++++++++++++++ INPUT +++++++++++++++++" << endl;
    //cout << testcase << endl;

    Community *comm = new Community();

    string id = "351055db-33e6-4f9b-bfe1-16f1ac446ac1";
    int status = comm->process(testcase);

    if(status == DATA_VALIDATE_SUCC) {
        cout << comm->getSnapShot(id) << endl;
    }

    delete comm;
    return 0;
}
