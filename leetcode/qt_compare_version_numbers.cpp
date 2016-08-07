/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:20:21+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:20:22+08:00
* @Inc: Microsoft, Apple
* @Difficulty: easy
* @Tag: String
*/


/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Solution 1
        /*
        int pre1 = -1;
        int pre2 = -1;
        int cur1 = 0;
        int cur2 = 0;
        while(pre1!=version1.size() || pre2!=version2.size()) {
            cur1 = (int)version1.find_first_of('.', pre1+1);
            cur2 = (int)version2.find_first_of('.', pre2+1);
            if(cur1 == std::string::npos) cur1 = (int)version1.size();
            if(cur2 == std::string::npos) cur2 = (int)version2.size();

            int num1;
            int num2;

            int size1 = (int)version1.size();
            int size2 = (int)version2.size();


            if(pre1 < size1) {
                num1 = stoi(version1.substr(pre1+1, cur1-pre1-1));
            } else {
                num1 = 0;
            }
            if(pre2 < size2) {
                num2 = stoi(version2.substr(pre2+1, cur2-pre2-1));
            } else {
                num2 = 0;
            }

            pre1 = cur1;
            pre2 = cur2;

            if(num1 == num2) continue;
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
        }
        return 0;
        */
        // Solution 2
        int i = 0;
        int j = 0;
        int n1 = version1.size();
        int n2 = version2.size();

        int num1 = 0;
        int num2 = 0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.'){
                num1 = num1*10+(version1[i]-'0');
                i++;
            }

            while(j<n2 && version2[j]!='.'){
                num2 = num2*10+(version2[j]-'0');
                j++;
            }

            if(num1>num2) return 1;
            else if(num1 < num2) return -1;

            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }

        return 0;
    }
};
