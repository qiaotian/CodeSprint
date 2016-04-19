class Solution {
public:
    string countAndSay(int n) {
        string curr = "1"; // curr is the first string now

        for(int i=1; i<n; i++) {
            string next;
            int count = 0;
            char start = curr[0];
            for(int j = 0; j < curr.size(); j++) {
                if(curr[j] == start) {
                    // same digit occurs
                    count++;
                } else {
                    // different digit occurs
                    next += (to_string(count) + start); // update next string
                    start = curr[j];
                    count = 1; // notice that the count is not 0
                }
                
                if(j == curr.size()-1) next += (to_string(count) + curr[j]); // update next string
            }
            curr = next;
        }
        return curr;
    }
};

/***
 * There two types conditions that I should update 'next' string
 * 1. the later digit differs with the former one
 * 2. the current digit is the last digit of the objective string
 * /
