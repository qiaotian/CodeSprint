class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        string res;
        path = path.substr(1);
        while(!path.empty()) {
            int n = path.find('/');
            string folder;
            if(n!=string::npos) {
                folder = path.substr(0, n);
                path = path.substr(n+1);
            } else {
                folder = path;
                path = "";
            }
            if(folder == "." || folder == "") {
                continue;
            } else if(folder == "..") {
                if(!dir.empty()) dir.pop_back();
            } else {
                dir.push_back(folder);
            }
        }
        if(dir.empty()) {
            res += '/';
        } else {
            for(int i=0; i<dir.size(); i++) {
                res += '/' + dir[i];
            }
        }

        return res;
    }
};
