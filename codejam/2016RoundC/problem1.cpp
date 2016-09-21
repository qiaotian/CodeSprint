#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> dir = {-1, 0, 1, 0, -1};
double expect = 0.0;

void maxexp(vector<vector<double>>& field, vector<double>& prob, int maxsteps, int start_row, int start_col) {
    if(field.empty() || field[0].empty()) return;

    if(maxsteps == 0) {
        double _expect = 0.0;
        for(int i=0; i<prob.size(); i++) _expect += i*prob[i];
        for(int i=0; i<prob.size(); i++) cout << prob[i] << " ";
        cout << endl;
        expect = max(expect, _expect);
        return;
    }

    int rows = field.size();
    int cols = field[0].size();

    for(int i = 0; i < maxsteps+1; i++) {
        for(int d = 0; d < 4; d++) {
            int dest_row = start_row + dir[d];
            int dest_col = start_col + dir[d+1];

            if(dest_row >= 0 && dest_row < rows && dest_col >=0 && dest_col < cols) {
                vector<double> prob_cp = prob;
                if(field[dest_row][dest_col] > 1e-6) {
                    double tmp = field[dest_row][dest_col]; //缓存抓到概率
                    field[dest_row][dest_col] = 0.0;

                    for(int j=0; j<=prob.size(); j++) {
                        if(j==0) {
                            prob[j] = prob_cp[j]*(1.0-tmp);
                            continue;
                        }
                        prob[j] = prob_cp[j-1]*tmp + prob_cp[j]*(1.0-tmp);
                    }

                    //for(int i=0; i<maxsteps+1; i++) cout << prob[i] << " ";
                    //cout << endl;

                    maxexp(field, prob, maxsteps-1, dest_row, dest_col);
                    field[dest_row][dest_col] = tmp;

                } else {
                    maxexp(field, prob, maxsteps-1, dest_row, dest_col);
                }
                prob = prob_cp; // recover prob
            }
        }
    }
}

/*
void maxexp(vector<vector<double>>& field, double prob, int grabs, int maxsteps,
            int start_row, int start_col, double& expect) {

    if(field.empty() || field[0].empty()) return;
    if(maxsteps == 0) {
        expect += prob*grabs;
        cout << expect << endl;
        return;
    }

    int rows = field.size();
    int cols = field[0].size();

    for(int i=0; i<maxsteps+1; i++) {
        for(int d=0; d<4; d++) {
            int dest_row = start_row + dir[d];
            int dest_col = start_col + dir[d+1];

            if(dest_row >= 0 && dest_row < rows &&
                dest_col >=0 && dest_col < cols) {
                double tmp = field[dest_row][dest_col]; //缓存抓到概率
                if(tmp > 1e-6) {
                    field[dest_row][dest_col] = 0.0; // 抓到
                    maxexp(field, prob*tmp, grabs+1, maxsteps-1, dest_row, dest_col, expect);
                    field[dest_row][dest_col] = tmp; // recover

                    maxexp(field, prob*(1.0-tmp), grabs, maxsteps-1, dest_row, dest_col, expect);
                } else {
                    maxexp(field, prob, grabs, maxsteps-1, dest_row, dest_col, expect);
                }
            }
        }
    }
}
*/

int main() {
    string ipath = "/Users/qiaotian/Desktop/RoundC/A-small-attempt2.in.txt";
    string opath = "/Users/qiaotian/Desktop/RoundC/o.txt";

    ifstream ifile(ipath);
    ofstream ofile(opath);

    if(!ifile) {
        cout << "open input file failed" << endl;
        return EXIT_FAILURE;
    }

    if(!ofile) {
        cout << "open output file failed" << endl;
        return EXIT_FAILURE;
    }

    string line;
    vector<double> ans;

    int cnt = 0;
    getline(ifile, line);
    cnt = stoi(line);
    for(int it=0; it<cnt; it++) {
        int steps = 0;
        int rows = 0, cols = 0;
        int rs = 0, cs = 0;

        getline(ifile, line);
        istringstream iss(line);
        iss >> rows >> cols >> rs >> cs >> steps;

        double p = 0.0, q=0.0;
        getline(ifile, line);
        istringstream iss2(line);
        iss2 >> p >> q;

        cout << "rows = " << rows << " cols = " << cols << endl;
        cout << "p = " << p << " and q = " << q << endl;
        cout << "max steps is " << steps << endl;

        vector<vector<double>> field(rows, vector<double>(cols, 0.0));

        for(int i=0; i<rows; i++) {
            getline(ifile, line);
            istringstream iss3(line);
            for(int j=0; j<cols; j++) {
                char tmp;
                iss3 >> tmp;
                if(tmp == '.') {
                    field[i][j] = q;
                } else if(tmp == 'A') {
                    field[i][j] = p;
                } else {
                    cout << "error" << endl;
                    return -1;
                }
            }
        }

        expect = 0.0;
        vector<double> prob(steps+1, 0.0);
        prob[0] = 1.0;
        maxexp(field, prob, steps, rs, cs);
        /*
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                cout << field[i][j] << " ";
            }
            cout << endl;
        }*/

        ofile << "Case #" << it+1 <<":";
        ofile << " " << expect;
        ofile << endl;
        expect = 0.0;
    }
    ifile.close();
    ofile.close();
    return 0;
}
