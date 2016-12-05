/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-11-27T10:06:52+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-11-27T10:06:52+08:00
*/


#include "predictor.h"

using namespace std;

//int main(int argc, char* argv[]) {
int main() {
    Predictor *pdt = new Predictor();

    if(pdt->prepare()) {
        delete pdt;
        return 1;
    }
    if(pdt->process()) {
        delete pdt;
        return 1;
    }
    cout << "Finished!" << endl;
    return 0;
}
