/*
Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
小Hi和小Ho经常用Playfair密码表加密自己的代码。 密码表是按以下步骤生成的。

1. 随机选择一个只包含大写字母的单词S作为密钥。  

2. 将S中的所有字母J替换为字母I。  

3. 将S中的字母依次填写进一个5x5的矩阵，按照从上到下、从左到右的顺序填充格子。填充过程中略过已经在密码表中的字母。  

4. 将'A'-'I', 'K'-'Z'(除去J之外的所有大写字母)中没有出现在密码表中的大写字母按照字母表顺序填入矩阵剩余的格子中。

举个例子：单词DIJSTRA，替换字母得到DIISTRA；将DIISTRA填入矩阵得到的密码表为(注意第二个I被略过了)：

DISTR
A....
.....
.....
.....
最后将剩余字母填入，得到密码表：

DISTR
ABCEF
GHKLM
NOPQU
VWXYZ
给定作为密钥的单词，你能求出密码表吗？

Input
第1行：一行字符串，只包含大写字母，长度不超过200

Output
共5行，每行5个字母，表示密码表。

Sample Input
HIHOCODER

Sample Output
HIOCD
ERABF
GKLMN
PQSTU
VWXYZ
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> encoding(string keyword) {
	vector<string> ans(5, "AAAAA");
    vector<bool> dict(26, false); // existed or not

    for(auto& c:keyword) if(c=='J') c = 'I'; // repalace 'J' with 'I'
    
    cout << keyword << endl;

    int row = 0; 
    int col = 0;
    for(int i=0; i<keyword.size(); i++) {
        if(dict[keyword[i]-'A']) continue;
        ans[row][col] = keyword[i];
        dict[keyword[i]-'A'] = true;

        col++;
        row+=(col/5);
        col%=5;
    }

    for(auto str:ans) cout << str << endl;

    // 处理剩余字符串
    vector<char> remains;
    for(int i=0; i<dict.size(); i++) {
        if(!dict[i] && i+'A'!='J') remains.push_back(i+'A');
    }
    int index = 0;
    for(int i=row, j=col; i<5 && j<5; j++, i+=(j/5), j%=5) {
        ans[i][j] = remains[index++];
    }

	return ans;
}

int main() {
    string input = "DIJSTRA";
    vector<string> ans = encoding(input);
    for(auto str:ans) {
        cout << str << endl;
    }
    return 0;
}
