/*
Problem

The Codejamon monsters talk in enciphered(加密的) messages. Here is how it works:

Each kind of monster has its own unique vocabulary: a list of V different words consisting only of lowercase English letters. When a monster speaks, it first forms a sentence of words in its vocabulary; the same word may appear multiple times in a sentence. Then, it turns the sentence into an enciphered string, as follows:

Randomly shuffle each word in the sentence.
Remove all spaces.
Understanding the monsters can bring you huge advantages, so you are building a tool to do that. As the first step, you want to be able to take an enciphered string and determine how many possible original sentences could have generated that enciphered string. For example, if a monster's vocabulary is ["this", "is", "a", "monster", "retsnom"], and it speaks the enciphered string "ishtsiarestmon", there are four possible original sentences:
"is this a monster"
"is this a retsnom"
"this is a monster"
"this is a retsnom"
You have S enciphered strings from the same monster. For each one, can you figure out the number of possible original sentences?

IMPORTANT: Since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 109 + 7 (1000000007).

Input:
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line with two integers V and S, the size of the monster's vocabulary and the number of enciphered strings. Then, V lines follow; each contains a single string of lowercase English letters, representing a word in the monster's vocabulary. Finally, S lines follow. Each contains a string consisting only of lowercase English letters, representing an enciphered sentence. It is guaranteed that all enciphered sentences are valid; that is, each one has at least one possible original sentence.

Output:
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a space separated list of of S integers: the answers (modulo 109 + 7) for each enciphered sentence, in the order given in the input, as described in the problem statement.

Limits:
1 ≤ T ≤ 100.
1 ≤ S ≤ 5.

Small dataset:
1 ≤ the length of each word in the monster's vocabulary ≤ 5.
1 ≤ the length of the enciphered string ≤ 50.
5 ≤ V ≤ 10.

Large dataset:
1 ≤ the length of each word in the monster's vocabulary ≤ 20.
2000 ≤ the length of the enciphered string ≤ 4000.
200 ≤ V ≤ 400.

Sample
Input:
2
5 1
this
is
a
good
day
sithsiaodogyad
5 3
pt
ybsb
xnydt
qtpb
kw
xnydttbpqtpqb
yxdtntpbsby
ptptxytdnsbybpt

Output:
Case #1: 2
Case #2: 1 1 1

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#define PB           push_back
#define MP(x,y)      make_pair(x,y)
#define CLR(x,y)     memset(x, y, sizeof(x))

#define FOR(i,l,r)   for(int i=l; i<=r; i++)
#define ROF(i,l,r)   for(int i=r; i>=l; i--)

#define RI(x)        ifile>>x
#define RII(x,y)     RI(x),RI(y)
#define RIII(x,y,z)  RI(x),RI(y),RI(z)

// 大数据集超时
int helper(unordered_map<string, int>& dict, string& sentence, int pos) {
    int ans = 0;
    int n = sentence.size();
    if(pos>=n) return 1;
    for(auto word:dict) {
        //cout << word.first << endl;
        string w = word.first;
        int cnt = word.second;
        if(n-pos<w.size()) continue;

        string l = sentence.substr(pos, w.size());
        sort(l.begin(), l.end());
        //cout << l << endl;
        if(w==l) ans += cnt*helper(dict, sentence, pos+l.size());
    }
    return ans;
}

// 改进 仍然超时, 说明瓶颈在于递归, 需要使用动归代替递归
int helper2(unordered_map<string, int>& dict, string& sentence, int pos) {
    int ans = 0;
    int n = sentence.size();

    if(pos >= n) return 1;
    string feature = "00000000000000000000000000";
    for(int i=pos; i<n && i<pos+21; i++) {
        feature[sentence[i]-'a']++;
        auto search = dict.find(feature);
        if(search != dict.end()) {
            ans += search->second*helper2(dict, sentence, i+1);
        }
    }
    return ans;
}

int helper3(unordered_map<string, int>& dict, string& sentence) {
    int ans = 0;
    int n = sentence.size();

    vector<int> dp(n+1, 0); // dp[i]表示前i个字符的组合数目
    dp[0] = 1;

    //string feature = "00000000000000000000000000"; 放置位置错误
    for(int i=1; i<=n; i++) {
        string feature = "00000000000000000000000000";
        for(int k=1; k<=20 && k<=i; k++) {
            // k is the char number to current position i
            feature[sentence[i-k]-'a']++;
            auto search = dict.find(feature);
            if(search != dict.end()) {
                dp[i] += search->second*dp[i-k];
                dp[i] %= 1000000007;
            }
        }
    }
    return dp[n];
}


int main() {
    string ipath = "./C-large-practice.in.txt";
    string opath = "./C-large-practice.out.txt";

    ifstream ifile(ipath);
    ofstream ofile(opath);

    if(!ifile || !ofile) {
        cout << "----> open files failed" << endl;
        return EXIT_FAILURE;
    }

    int T;
    RI(T);
    for(int t=0; t<T; t++) {
        int V, S;
        RII(V, S);
        /*
        unordered_map<string, int> dict;
        for(int i=0; i<V; i++) {
            string tmp;
            RI(tmp);
            sort(tmp.begin(), tmp.end());
            dict[tmp]++;
        }
        */
        // 改造dict
        unordered_map<string, int> dict; // map feature to count
        for(int i=0; i<V; i++) {
            string tmp;
            RI(tmp);
            string feature = "00000000000000000000000000"; // 26个字母出现的次数
            for(auto c:tmp) feature[c-'a']++;
            dict[feature]++;
            //cout << feature << endl;
        }

        string ans = "";
        for(int i=0; i<S; i++) {
            string tmp;
            RI(tmp);
            //int cnt = helper(dict, tmp, 0);
            //int cnt = helper2(dict, tmp, 0);
            int cnt  = helper3(dict, tmp);
            ans += to_string(cnt);
            if(i!=S-1) ans += " ";
        }

        ofile << "Case #" << t+1 <<": " << ans << endl;
    }

    ifile.close();
    ofile.close();
    return 0;
}
