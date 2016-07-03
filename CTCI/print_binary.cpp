/**
* @Author: Tian Qiao
* @Date:   2016-07-03T18:02:08+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T18:25:37+08:00
*/



/*Given a(decimal -e.g. 3.72) number that is passed in as a string, print the binary representation. If the number can not be represented accurately in binary, print "ERROR".*/

________________________________________________________________________________

/*First, let's start off by asking ourselves what a non-integer number in binary looks like. By analogy to decimal number, the number n = 0.101 = 1*(1/2^1) + 0*(1/2^2) + 1*(1/2^3).
Print the int part of n is straight-forward(see below). To print the decimal part, we can multiply by 2 and check if the 2*n is greater than or equal to one. This essentially "shifting" the fractional sum. That is:
    r = 2*n = 2*0.101 = 1*(1/2^0) + 0*(1/2^1) + 1*(1/2^2) = 1.01
If r>=1, then we know that n had a 1 right after the decimal point. By doing this continuously, we can check every digit.*/

class Solution {
public:
    string printBinary(string n) {
        int dot = n.find('.');
        int integerPart = 0; // the integer part of n
        double decimalPart = 0.0; // the decimal part of n
        if(dot = string::npos) {
            // 没有小数部分
            integerPart = stoi(n); // stoi (STL::string), atoi (C math)
            decimalPart = 0.0;
        } else {
            integerPart = stoi(n.substr(0, dot));
            decimalPart = stod(n)-integerPart;
        }

        string integerStr;
        string decimalStr;
        while(integerPart>0) {
            int r = integerPart%2;
            integerStr = (r==1?"1":"0")+integerStr;
            integerPart>>=1;
        }
        while(decimalPart>0) {
            if(decimalStr.size()>32) return "ERROR";
            if(decimalPart==1) {
                decimalStr += "1";
                break;
            }
            double r = decimalPart*2;
            decimalStr += r>=1?"1":"0";
            decimalPart = r-(r>=1?1:0);
        }
        return integerStr+"."+decimalStr;
    }
};
