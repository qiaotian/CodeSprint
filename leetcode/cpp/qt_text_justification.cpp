/**
* @Author: Tian Qiao
* @Date:   2016-08-05T01:34:25+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-05T01:34:27+08:00
* @Inc: LinkedIn, Airbnb
* @Difficulty: Hard
*/

// 细节题
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        if(maxWidth < 2) return words;

        string line;
        int len = 0;
        int start = 0;    // 当前行的第一个单词索引
        int wordsCnt = 0; // 当前行的单词数
        int spaceCnt = 0; // 当前行的空格数

        int i=0;
        for(i=0; i<words.size(); i++) {
            len += words[i].size();
            if(len+i-start <= maxWidth) continue;

            len -= words[i].size(); // 删除多余单词
            i--; // 删除多余单词，将i指向当前行的最后一个单词

            wordsCnt = i-start+1;
            spaceCnt = maxWidth-len;

            // 一定不是最后一行
            if(wordsCnt==1) {
                string empStr(spaceCnt, ' ');
                line+=words[start];
                line+=empStr;
                ans.push_back(line);
                line="";
                len=0;
                start = i+1;
                wordsCnt=0;
                spaceCnt=0;
            } else if(wordsCnt > 1) {
                int averageCnt = spaceCnt/(wordsCnt-1);
                int remainsCnt = spaceCnt%(wordsCnt-1);
                for(int j=start; j<=i; j++) {
                    line+=words[j];
                    if(j==i) continue;
                    string empStr(averageCnt, ' ');
                    line+=empStr;
                    if(j-start<remainsCnt) line+=" ";
                }
                ans.push_back(line);
                line="";
                len=0;
                start = i+1;
                wordsCnt=0;
                spaceCnt=0;
            }
        }
        // 处理最后一行
        int last = 0;
        for(int j=start; j<words.size(); j++) {
            line+=words[j];
            last+=words[j].size();
            line+=(j==words.size()-1?"":" ");
            last+=(j!=words.size()-1);
        }
        string empStr(maxWidth-last, ' ');
        line+=empStr;
        ans.push_back(line);

        return ans;
    }
};
