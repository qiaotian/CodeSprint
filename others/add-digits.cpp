// Time:  O(1)
// Space: O(1)
// Digit root problem

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1; //
    }
};
