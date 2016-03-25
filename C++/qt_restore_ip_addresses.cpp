class Solution {
    void dfs(string& s, int start, vector<string>& ip, vector<string>& res) {
        if(ip.size()==4 && start==s.size()) {
            res.push_back(ip[0]+'.'+ip[1]+'.'+ip[2]+'.'+ip[3]);
            return;
        }

        //if(s.size() - start + 1 > 3*(4-ip.size())) return;
        //if(s.size() - start + 1 < 4-ip.size()) return;

        //注意这里杜绝发生以上错误
        if(s.size() - start > 3*(4-ip.size())) return; //ip地址每一段都分到超过三个字符
        if(s.size() - start < 4-ip.size()) return; //ip地址每一段都分不到一个字符

        int num = 0;
        for(int i = 0; i < 3; i++) {
            num = num*10 + s[start+i]-'0';

            if(num > 255 || num < 0) continue;

            string tmp = s.substr(start, i+1);
            ip.push_back(tmp);
            dfs(s, start+i+1, ip, res);
            ip.pop_back();

            if(num == 0) return;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        dfs(s, 0, ip, res);
        return res;
    }
};
