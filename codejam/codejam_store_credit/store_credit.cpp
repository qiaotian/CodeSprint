//
//  main.cpp
//  TEST
//
//  Created by QiaoTian on 2/15/16.
//  Copyright © 2016 State Key Laboratory of Intelligent Technology and Systems. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>

#include <iostream>
#include <fstream>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second < b.second) {
        return true;
    } else {
        return false;
    }
}

void util(vector<pair<int, int>>& prices, int sum, vector<int>& selections) {
    int left = 0, right = (int)prices.size()-1;
    while (left < right) {
        int tmp = prices[left].second + prices[right].second;
        if(tmp == sum) {
            selections[0] = prices[left].first+1;
            selections[1] = prices[right].first+1;
            if (selections[0] > selections[1]) {
                swap(selections[0], selections[1]);
            }
            return;
        } else if(tmp > sum) {
            right--;
        } else {
            left++;
        }
    }

}

int main(int argc, const char * argv[]) {
    //string inpath = "/Users/qiaotian/Downloads/A-small-practice.in.txt";
    //string outpath = "/Users/qiaotian/Downloads/A-small-practice.out.txt";
    string inpath = argv[1];
    string outpath = argv[2];
    
    ifstream infile(inpath);
    if(!infile) {
        cout << "could not open infile" << endl;
        exit(EXIT_FAILURE);
    }
    ofstream outfile(outpath);
    if (!outfile) {
        cout << "could not open outfile" << endl;
        exit(EXIT_FAILURE);
    }
    
    int num_cases = 0, sum = 0, count = 0;
    int i = 0;
    vector<pair<int, int>> prices; // index and price
    vector<int> selections(2, 0);
    int price = 0;
    
    infile >> num_cases;
    while (i < num_cases) {
        infile >> sum;
        infile >> count;
        prices.clear();
        for (int j = 0; j<count; j++) {
            infile >> price;
            prices.push_back(make_pair(j, price));
        }
        
        sort(prices.begin(), prices.end(), compare);
        util(prices, sum, selections);
        
        outfile << "Case #" << i+1 << ": " << selections[0] << " " << selections[1] << endl;
        
        i++;
    }
    
    return 0;
}


