#include <iostream>
#include <vector>

using namespace std;

bool util(vector<int>& gift, int n) {
    vector<int> dict(n+1, 0);

    for(int i=0; i<n+1 && i<gift.size(); i++) dict[gift[i]]++;

    for(auto val:dict) {
        if(val>=3) {
            return true;
        }
    }
    for(int i=0; i<gift.size(); i++) {
        //for(int j=0;j<6; j++) cout << gift[j] << " ";
        //cout << endl;

        for(auto val:dict) {
            if(val>=3) return true;
        }
        if(i+n >= gift.size()) break;

        dict[gift[i]]--;
        dict[gift[i+n+1]]++;
    }
    return false;
}

int main() {
	int cnt;
    string line;
    cin >> cnt;
    for(int it=0; it<cnt; it++) {
        bool can = false;
    	int n, l;
        cin >> n >> l;
        vector<int> gift;
        for(int i=0; i<l; i++) {
            int tmp;
            cin >> tmp;
            gift.push_back(tmp);

            can = util(gift, n);
            if(can) break;
        }
        if(can) cout << "B" << endl;
        else cout << "CAN'T DECIDE" << endl;
    }
    return 0;
}
