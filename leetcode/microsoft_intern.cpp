//
//  main.cpp
//  MicrosoftIntern
//
//  Created by QiaoTian on 4/6/16.
//  Copyright © 2016 State Key Laboratory of Intelligent Technology and Systems. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<pair<string, bool>> rules;
vector<string> tests;
vector<string> ret;

bool isValid(string addr) {
    for(int i=0; i<rules.size(); ++i) {
        bool allow = rules[i].second;
        string rule = rules[i].first;
        
        int mask = 0;
        if(rule[rule.size()-2] == '/') {
            mask = stoi(rule.substr((int)rule.size()-1, 1));
        }
        else {
            mask = stoi(rule.substr((int)rule.size()-2, 2));
        }
        int a = 0;
        int b = 0;
        
        vector<int> ip1; // rule
        vector<int> ip2; // addr
        
        for(int j=0; j<rule.size(); j++) {
            if(rule[j]=='/') {ip1.push_back(a); break;}
            if(rule[j]=='.') {ip1.push_back(a); a = 0; continue;}
            a = a*10 + (rule[j]-'0');
        }
        
        for(int j=0; j<addr.size(); j++) {
            if(addr[j]=='.') {ip2.push_back(b); b = 0; continue;}
            b = b*10 + (addr[j]-'0');
            if(j==addr.size()-1) ip2.push_back(b);
        }
        
        if(mask<8) {
            mask = 8-mask%8;
            if(ip1[0]>>mask == ip2[0]>>mask) return allow;
        } else if(mask<16) {
            mask = 8-mask%8;
            if(ip1[0]==ip2[0] && ip1[1]>>mask == ip2[1]>>mask) return allow;
        } else if(mask<24) {
            mask = 8-mask%8;
            if(ip1[0]==ip2[0] && ip1[1]==ip2[1] && ip1[2]>>mask == ip2[2]>>mask) return allow;
        } else if(mask<32){
            mask = 8-mask%8;
            if(ip1[0]==ip2[0] && ip1[1]==ip2[1] && ip1[2]==ip2[2] && ip1[3]>>mask == ip2[3]>>mask) return allow;
        } else {
            if(ip1[0]==ip2[0] && ip1[1]==ip2[1] && ip1[2]==ip2[2] && ip1[3] == ip2[3]) return allow;
        }
    }
    
    return true; // allow
}


int main(int argc, const char * argv[]) {
    int M, N;
    scanf("%d %d", &M, &N);
    
    for(int i=0; i<M; i++) {
        char _command[100];
        char _address[100];
        //cin >> command >> address;
        scanf("%s %s", _command, _address);
        string command(_command);
        string address(_address);
        
        if(address[address.size()-2]!='/' && address[address.size()-3]!='/') address+="/32";
        
        if(command == "allow") rules.push_back(make_pair(address, true));
        else rules.push_back(make_pair(address, false));
    }
    
    for(int i=0; i<N; i++) {
        string address;
        cin >> address;
        tests.push_back(address);
    }
    
    // process and output
    for(int i=0; i<N; i++) {
        string testaddr = tests[i];
        bool valid = isValid(testaddr);
        cout << (valid?"YES":"NO") << endl;
    }
    
    return 0;
}


/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fontsize(int N,int P,int W,int H);

int main(void){
    int job;
    while(cin>>job){
        for(int i=0;i<job;i++){
            int N,P,W,H;
            cin>>N>>P>>W>>H;
            int res = fontsize(N,P,W,H);
            cout<<res<<endl;
        }
    }
    return 0;
}

int fontsize(int N,int P,int W,int H){
    int res;
    vector<int> nums(N,0);
    for(int i = 0; i < N; i++) cin>>nums[i];
    
    int max_s = min(W, H);
    for(int i = max_s; i >= 1; i--){
        int count_w = W/i, count_h = H/i;
        int max_line = count_h*P;
        int sum=0;
        for(int j=0; j<N; j++){
            if(nums[j]%count_w == 0) sum += (nums[j]/count_w);
            else sum += (nums[j]/count_w)+1;
        }
        if(sum <= max_line){
            res = i;
            break;
        }
    }
    return res;
}
 */


/*
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <map>

using namespace std;

string cache[200];

int foo[200][200][2];

int main(int argc, char* argv[]) {

    int m, n;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cache[i];
    }

    int max = n * m * 10;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            foo[i][j][0] = max;
            foo[i][j][1] = max;
        }
    }
 
    for (int i = n - 1; i >=0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int x = (cache[i][j] == '.') ? 0 : 1;
            if (i == n - 1 && j == m - 1) {
                foo[i][j][0] = x;
                foo[i][j][1] = x;
            } else {
                if (i == n - 1) {
                    foo[i][j][0] = foo[i][j + 1][0] + x;
                    foo[i][j][1] = foo[i][j + 1][0] + x;
                } else if (j == m - 1) {
                    foo[i][j][0] = foo[i + 1][j][1] + x;
                    foo[i][j][1] = foo[i + 1][j][1] + x;
                } else {
                    int rr = (cache[i][j + 1] == '.') ? 0 : 1;
                    int dd = (cache[i + 1][j] == '.') ? 0 : 1;
                    
                    foo[i][j][0] = foo[i][j + 1][0] + x;
                    if (rr == 1) {
                        int tmp = foo[i + 1][j][1] + x;
                        if (tmp < foo[i][j][0]) {
                            foo[i][j][0] = tmp;
                        }
                    }
                    
                    foo[i][j][1] = foo[i + 1][j][1] + x;
                    if (dd == 1) {
                        int tmp = foo[i][j + 1][0] + x;
                        if (tmp < foo[i][j][1]) {
                            foo[i][j][1] = tmp;
                        }
                    }
                }
            }
        }
    }
    cout << foo[0][0][0] << endl;
    return 0;
}
 */
