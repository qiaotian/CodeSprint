// nums中的数字必须是严格按照{1,2,3,...,N}的形式组合
// 异常情况：存在数字重复、增长不连续、最大数字超过N
// 错误思路：用{1,2,3,...,N}与nums中的所有数字异或操作得到0，即是perm，反之则不。nums是permutaion时此条件满足，但是此条件不足以推导出nums是perm。
// 正确思路：使用hash检测每个元素是否重复出现，同时检查是否出现越界情况。

clsss Solution {
public:
    bool solution(vector<int>& nums) {
        vector<bool> flags(nums.size()+1, false); //均未出现过
        for(auto num:nums) {
            // 越界或者重复都不是permutation
            if(num>nums.size() || num<1 || flags[num]) return false; //
            flags[num] = true;
        }
        return true;
    }
};
