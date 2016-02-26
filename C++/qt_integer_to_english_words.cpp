// 1st solution (beats 9%, bad)
/*
class Solution {
    map<int, string> dict = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
    };
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string str;
        int i = 0;
        while(num) {
            string sstr;
            int tmp = num%1000;
            if(tmp/100) sstr += dict[(tmp/100)] + " " + dict[100] + " ";
            tmp %= 100;
            if(tmp/20) {
                // tmp is bigger or equal to 20 
                sstr += dict[(tmp/10)*10] + " ";
                if(tmp%10) sstr += dict[tmp%10] + " ";
            } else if (tmp != 0){
                //tmp is less than 20
                sstr += dict[tmp] + " ";
            } else {
                // tmp == 0
            }
            num /= 1000;
            if(i == 0) sstr += " ";
            else if(i == 1 && sstr != "") sstr += dict[1000] + " ";
            else if(i == 2 && sstr != "") sstr += dict[1000000] + " ";
            else if(i == 3 && sstr != "") sstr += dict[1000000000] + " ";
            else {// do nothing
            }
            i++;
            str = sstr + str;
        }
        int len = str.size();
        return str.substr(0, len-2);
    }
};
*/

// 2nd solution (Beats 73% , good)
class Solution {
public:
    static string numberToWords(int n) {
        if(n == 0) return "Zero";
        else return int_string(n).substr(1);
    }
private:
    static const char * const below_20[];
    static const char * const below_100[];
    static string int_string(int n) {
        if(n >= 1000000000)   return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
        else if(n >= 1000000) return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if(n >= 1000)    return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if(n >= 100)     return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        else if(n >= 20)      return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if(n >= 1)       return string(" ") + below_20[n - 1];
        else return "";
    }
};

const char * const Solution::below_20[] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char * const Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
