#include <iostream>
#include "Community.h"

using namespace std;

class Tester {
public:
    Tester(){ this->comm = new Community(); }
    ~Tester(){ delete this->comm; }

    void run();
    void addCase(string str);
private:
    vector<string> testCases;
    Community *comm;
};
