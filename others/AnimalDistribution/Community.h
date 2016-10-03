#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

enum PROCESS_STATUS{
    DATA_VALIDATE_SUCC,
    DATA_VALIDATE_FAIL
};

struct SnapShot {
    public:
        string id;
        string timestr;
        map<string, pair<int, int>> animals; // id to position
        SnapShot(){}
        SnapShot(string id, string timestr):id(id), timestr(timestr) {}
};

class Community {
    public:
        Community(){}
        ~Community(){}

        int process(string& historyData); // check data validation and prepare for calling
        string getSnapShot(string id);    // excute process before call this
        string getSnapShot(string& historyData, string id);

    private:
        bool regDate(string timestr);
        pair<string, vector<int>> locateAnimal(string line);
        unordered_map<string, SnapShot> snapshot_dict;      // find snapshot's animals
        unordered_map<string, pair<int, int>> animal_dict;  // find animal's position
};
