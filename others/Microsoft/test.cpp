#include <string>

using namespace std;

class A {
    
};

class B:public A {
    string str;
};

int main() {
    A *p = new B;
    delete p;
    return 0;
}
