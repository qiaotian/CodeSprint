class Solution {
    vector<int> singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (int n : nums) a ^= n;
    for (int n : nums) 
        if (n & a & -a) b ^= n;
    return {a ^ b, b};
}
};
