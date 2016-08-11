/*

ven a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.*/



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int start = digits.size()-1;
        while(digits[start]==9 && start>=0) {
            digits[start] = 0;
            start--;
        }
        if(start<0) {
            auto it = digits.begin();
            digits.insert(it, 1);
        } else {
            digits[start]++;
        }
        return digits;
    }
};
