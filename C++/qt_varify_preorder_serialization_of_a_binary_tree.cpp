// 1st solution
/*
class Solution {
private:
    void collect(string preorder, vector<int>& nums) {
        int idx = 0;
        int num = 0;
        while(idx < preorder.size()){
            if(preorder[idx]<='9' && preorder[idx]>='0') {
                num = 10*num+preorder[idx]-'0';
            }
            if(preorder[idx]=='#') {
                num = -1;
            }
            if(preorder[idx]==',' || idx == preorder.size()-1) {
                nums.push_back(num);
                num = 0;
            }
            idx++;
        }
    }
public:
    bool isValidSerialization(string preorder) {
        vector<int> nums; 
        collect(preorder, nums);
        
        int nodeCnt=0, nullCnt=0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == -1) ++nullCnt;
            else ++nodeCnt;
            if(nullCnt >= nodeCnt+1 && i!=nums.size()-1) return false;
        }
        return nullCnt == nodeCnt+1;
    }
};
*/

// 2nd solution
/*
class Solution {
public:
    bool isValidSerialization(string preorder) {
        replace(preorder.begin(),preorder.end(),',',' ');
        stringstream ss(preorder);
        string value;
        int nbTreeToRead = 1;
        while(ss >> value)
        {
            if (nbTreeToRead == 0) return false;
            if (value == "#") nbTreeToRead --;
            else nbTreeToRead++;
        }
        return (nbTreeToRead == 0);
    }
};
*/

// 3rd solution
class Solution {
public:
    bool go(int &root, const string &preorder) {
        if (preorder[root] == '#') {
            return root == preorder.size() - 1;
        }
        for (int i = 1; i <= 2; i++) {
            while (root < preorder.size() and preorder[root] != ',') root++;
            root++;
            if (root >= preorder.size()) return false;
            if (preorder[root] != '#' && go(root, preorder) == false) return false;
        }
        return true;
    }

    bool isValidSerialization(string preorder) {
        int cur = 0;
        bool flag = go(cur, preorder);
        if (cur >= preorder.size() - 1 and flag) return true;
        return false;
    }
};

/**
 * WARNINGS
 * 1. Extract an array from the string given;
 * 2. We cannot assume the number only has one digit;
 * 
 * SOLUTIONS
 * 1. use two integers to represent the digit and '#' and give a judgement;
 * 2. use one interger (PS using streamstream that's a concise method to divide string)
 * 3. ????
 * 
 * REFERENCES
 * 1. https://leetcode.com/discuss/84073/straight-forward-c-solution-with-explanation
 * /
