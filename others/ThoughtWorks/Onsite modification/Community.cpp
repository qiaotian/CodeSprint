#include "Community.h"
#include <regex>
#include <cstring>

/// Extract id and position from the input string
bool Community::regDate(string timestr) {
    if(timestr.size() != 19)  return false;

    string pattern = "((19|20)\\d\\d)/(0?[1-9]|1[012])/(0?[1-9]|[12][0-9]|3[01]) ([2][0-3]|[0-1][0-9]|[1-9]):[0-5][0-9]:([0-5][0-9]|[6][0])$";

    return regex_match(timestr, regex(pattern));
}

pair<string, vector<int>> Community::locateAnimal(string line) {
    string id;
    vector<int> location;

    istringstream iss(line);
    int tmp;
    iss >> id;
    for(int tmp; iss>>tmp;) {
        location.push_back(tmp);
    }
    return {id, location};
}

int Community::process(string& historyData) {
    // return 0: sucess
    // return 1: invalid format
    // return 2: data conflict
    istringstream iss(historyData);

    string snapshot_id, snapshot_time;
    while(getline(iss, snapshot_id) && getline(iss, snapshot_time)) {
        // check validation
        if(!regDate(snapshot_time)) {
            cout << "Invalid format" << endl;
            return 1;
        }

        // process the current snapshot
        SnapShot snapshot(snapshot_id, snapshot_time);

        // read in animal infomation
        string str;
        while(getline(iss, str)) {
            if(str.empty()) {
                // insert new snapshot in dict
                for(auto i:animal_dict) {
                    snapshot.animals.insert({i.first, i.second});
                }
                snapshot_dict.insert({snapshot_id, snapshot});
                break;
            }

            pair<string, vector<int>> location = locateAnimal(str);
            string animal_id = location.first;
            vector<int> animal_pos = location.second;

            if(animal_pos.size() != 2 && animal_pos.size() != 4) {
                cout << "Invalid format" << endl;
                return 1;
            }

            auto search = animal_dict.find(animal_id);
            if(search != animal_dict.end()) {
                // this animal existed before
                if(animal_pos.size() == 2) {
                    cout << animal_id << "doesn't exist before" << endl;
                    return 1;
                }
                pair<int, int> prepos = search->second;
                if(prepos != make_pair(animal_pos[0], animal_pos[1])) {
                    cout << "Conflict found at " << snapshot_id << endl;
                    return 2;
                } else {
                    search->second.first = animal_pos[0]+animal_pos[2];
                    search->second.second = animal_pos[1]+animal_pos[3];
                }
            } else {
                // new animal
                animal_dict[animal_id] = {animal_pos[0], animal_pos[1]};
                initPos[animal_id] = {animal_pos[0], animal_pos[1]};
            }
        }
    }
    return 0;
}

string Community::getSnapShot(string& historyData, string id) {
    // excute process before getSnapShot
    string ans;
    Community::process(historyData);
    SnapShot snapshot = snapshot_dict[id];

    for(auto animal : snapshot.animals) {
        ans  +=  animal.first + " " +
                  to_string(animal.second.first) + " " +
                  to_string(animal.second.second) + " " + '\n';
    }
    return ans;
}

/*
string Community::getSnapShot(string id) {
    string ans = "";
    SnapShot snapshot = snapshot_dict[id];

    for(auto animal : snapshot.animals) {
        ans  +=  animal.first + " " +
                  to_string(animal.second.first) + " " +
                  to_string(animal.second.second) + '\n';
    }
    return ans;
}*/

string Community::getSnapShot(string id) {
    // excute process before getSnapShot
    string ans = "";
    SnapShot snapshot = snapshot_dict[id];

    for(auto animal : snapshot.animals) {
        ans  +=  animal.first + " " +
                  to_string(animal.second.first) + " " +
                  to_string(animal.second.second) + " " +
                  to_string(initPos[animal.first].first) + " " +
                  to_string(initPos[animal.first].second) + '\n';
    }
    return ans;
}
