#include "Tester.h"

void Tester::addCase(string str) {
    this->testCases.push_back(str);
}
void Tester::run(){
    for(int i=0; i<testCases.size(); i++) {
        cout << "Test Case " << i+1 << ":" << endl;
        if(this->comm->process(testCases[i])){
            this->comm->getSnapShot("dcfa0c7a-5855-4ed2-bc8c-4accae8bd155");
        }
    }
}
