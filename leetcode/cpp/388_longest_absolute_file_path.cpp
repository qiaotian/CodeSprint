/*
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        if(input.empty()) return 0;
        
        input += '\n';
        int n = input.size();
        int ans = INT_MIN;
        vector<int> dp(1000, 0);    // dp[1]表示第1级目录的长度
        string cur = "";            // 当前字符串
        int cnt = 0;                // 当前字符串所处层级, cnt=0表示根目录，即\t的个数
        for(int i=0; i<n; i++) {
            if(input[i]=='\t') cnt++; // 新字符串开始
            else if(input[i]=='\n') { // 字符串结束
                // cout << dp[-1] << endl; // 竟然没有报错，而且输出0!!!
                dp[cnt] = (cnt>0?dp[cnt-1]:0)+(int)cur.size();
                if(cur.find('.')!=string::npos) 
                    ans = max(ans, dp[cnt]+cnt); //将‘/’的数目计算在内
                cur = "";
                cnt = 0;
            }
            else cur+=input[i];
        }
        return ans==INT_MIN?0:ans;
    }
};
