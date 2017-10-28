/**
 * @Author: qiao
 * @Date:   2017-08-14T20:53:11+08:00
 * @Email:  qiaotian@me.com
 * @Last modified by:   qiao
 * @Last modified time: 2017-08-15T18:15:26+08:00
 * @License: MIT
 * @Copyright: qiaotian
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define PB(x)        push_back(x)
#define MP(x,y)      make_pair(x,y)
#define CLR(x,y)     memset(x, y, sizeof(x))

#define FOR(i,l,r)   for(int i=l; i<=r; i++)
#define ROF(i,l,r)   for(int i=r; i>=l; i--)

#define IFSTREAM(x)  ifstream ifile(x)
#define OFSTREAM(y)  ofstream ofile(y)
#define CHECK()      if(!ifile || !ofile) {\
                         cout << "----> open files failed" << endl;\
                         return EXIT_FAILURE;\
                     }
#define OFILE        ofile
#define PRINT(x,t)   OFILE << "Case #" << t+1 <<": " << x << endl;
#define ICLOSE()     ifile.close()
#define OCLOSE()     ofile.close()
#define RI(x)        ifile>>x
#define RII(x,y)     RI(x),RI(y)
#define RIII(x,y,z)  RI(x),RI(y),RI(z)

string multiply(string num1, string num2)
   {
       string rs(num1.length()+num2.length(), '0');

       for (int i = num1.length()-1, d = rs.length()-1; i >= 0; i--, d--)
       {
           int carry = 0, k = d;
           for (int j = num2.length()-1; j >= 0; j--, k--)
           {
               int a = num1[i] - '0';
               int b = num2[j] - '0';
               a = a*b+carry + (rs[k]-'0');
               carry = a/10;
               rs[k] = a%10 + '0';
           }
           while (carry)
           {
               int sum = carry + (rs[k]-'0');
               carry = sum / 10;
               rs[k--] = sum % 10 + '0';
           }
       }
       while (rs.size() > 1 && rs[0] == '0') rs.erase(rs.begin());
       return rs;
}

string add(string num1,string num2){
    if(num1.size()<num2.size()){
        string temp=num1;
        num1=num2;
        num2=temp;
    }
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;
    while(length1>0){
        a=num1[length1-1]-'0';
        if(length2>0)
            b=num2[length2-1]-'0';
        else
            b=0;
        sum=a+b+flag;
        if(sum>=10){
            num1[length1-1]='0'+sum%10;
            flag=1;
        }else{
            num1[length1-1]='0'+sum;
            flag=0;
        }
        length1--;
        length2--;
    }
    if(1==flag)
        num1="1"+num1;
    return num1;
}

int main() {
    //string ipath = "./test.txt";
    //string opath = "./D-small-practice.out.txt";
    IFSTREAM("./A-small-attempt0.in.txt");
    CHECK();

    int T;
    RI(T);
    FOR(t, 0, T-1) {
        string pattern;
        long long start, end;
        RI(pattern);
        RII(start, end);

        string ans = "0";

        int n = pattern.size();
        int red = 0;
        int blue = 0;

        FOR(i, 0, n-1) {
            if(pattern[i]=='B') blue++;
        }
        long long l = (start-1)/pattern.size();
        long long r = (end-1)/pattern.size();
        //cout << "L:" << l << "R:" << r << endl;
        //cout << r-l-1 << " " << blue << endl;
        if(r-l-1>=0) {
            ans = multiply(to_string(r-l-1), to_string(blue));
        }

        if(l==r) {
            FOR(i, (start-1)%n, (end-1)%n) {
                if(pattern[i]=='B') ans = add(ans,"1");
            }
        } else {
            FOR(i, (start-1)%n, n-1) {
                if(pattern[i]=='B') ans = add(ans,"1");
            }

            FOR(i, 0, (end-1)%n) {
                if(pattern[i]=='B') ans = add(ans,"1");
            }
        }
        cout << "BLUE:" << ans << endl;
        /*
        int N, M, L;
        RIII(N, M, L);
        vector<vector<int>> info;
        FOR(i, 0, N-1) {
            vector<int> tmp;
            int A, B, P;
            RIII(A, B, P);
            tmp.PB(A), tmp.PB(B), tmp.PB(P);
            info.PB(tmp);
        }
        */
        // int ans = minPrice2(info, M, L);
        //int ans = minPrice(info, M, L);
        //string res = ans==-1?"IMPOSSIBLE":to_string(ans);
        PRINT(ans, t);

    }

    ICLOSE();
    OCLOSE();
    return 0;
}
