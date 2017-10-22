class Solution {
private:
/* idiot idea
    int compareNumbers(int a, int b) {
        // return 1 if a > b
        // return 0 if a = b
        // return -1 if a < b
        string astr = to_string(a);
        string bstr = to_string(b);
        if(a == b) return 0;
        
        // from left to right
        int len_a = astr.size();
        int len_b = bstr.size();
        int index_a = 0, index_b = 0;
        while(index_a < len_a && index_b < len_b) {
            if(astr[index_a] > bstr[index_b]) return 1;
            if(astr[index_a] < bstr[index_b]) return -1;
            index_a++;
            index_b++;
        }
        // from right to left
        index_a = len_a-1, index_b = len_b-1;
        while(index_a >= 0 && index_b >= 0) {
            if(astr[index_a] > bstr[index_b]) return 1;
            if(astr[index_a] < bstr[index_b]) return -1;
            index_a--;
            index_b--;
        }
        
        return 0;
    }
*/
    // must use static function
    static bool compFunction (int a, int b) {
        return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
    }
public:
/* idiot idea
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = 1; j < n - i; j++) {
                if(compareNumbers(nums[j-1], nums[j]) < 0) swap(nums[j-1], nums[j]);
            }
        }
        string res;
        bool hasNonzero = false;
        for(int i = 0; i < n; ) {
            if(nums[i] == 0 && !hasNonzero) continue;
            else hasNonzero = true;
            res += to_string(nums[i]);
        }
        return res.size()==0?"0":res;
    }
*/ 
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) return "";
        sort(nums.begin(), nums.end(), compFunction);
        string res = "";
        for (auto num : nums)
            res += to_string(num);
        //remove redundant zeroes
        if (res.length() != 0) {
            int i = 0;
            while (res[i] == '0' && i < res.length() - 1) i++;
            res = res.substr(i);
        }
        return res;
    }
};

// 2nd solution (shorter)
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(arr.begin(), arr.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        
        string res;
        for(auto s:arr) res+=s;
        while(res[0]=='0' && res.length()>1) res.erase(0,1);
        return  res;
    }
};
