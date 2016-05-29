class Solution {
public:
    void reverseWords(string &s) {
        vector<string> vec;
        string str;
        for(int i = 0; i<s.size(); i++) {
            //if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) {
            if(s[i]!=' ') {
                str+=s[i];
                continue;
            }
            if(s[i]==' ' && !str.empty()) {
                vec.push_back(str);
                str = "";
                continue;
            }
        }

        if(!str.empty()) vec.push_back(str);

        s = "";
        for(int i=vec.size()-1; i>=0; i--) {
            s+= vec[i];
            if(i!=0) s+=' ';
        }
    }
};
