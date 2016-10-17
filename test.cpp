#include <iostream>
#include <vector>

using namespace std;

class Stack {
    public:
        void push(int val) const;
        int pop();
        int getCount() const;
    private:
        int m;
        int n;
};

class Point
{
public:
    static int m;
    Point() {
        m++;
    }
    ~Point() {
        m--;
    }
    void init(){}
    static void output(){
        cout << m << endl;
    }
};

int Point::m = 0; // 静态变量使用前需要初始化

struct Alignment {
    //char b;
    //char c;
    char d;
    static int a;
};

int main()
{
    //Point::init(); //  error: call to non-static member function without an object argument

    //Point::output();
    Point pt;
    pt.init();
    pt.output();


    Alignment tmp;
    cout << sizeof(tmp) << endl;
    return 0;
}
