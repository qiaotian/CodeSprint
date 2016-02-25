// 1st solution (Time Complexity: O(32*N))
class Solution {  
public:  
    int singleNumber(vector<int>& nums) {  
        int bitnum[32]={0};  
        int res=0;  
        for(int i=0; i<32; i++){  
            for(int j=0; j<n; j++){  
                bitnum[i]+=(nums[j]>>i)&1;  
            }  
            res|=(bitnum[i]%3)<<i;  
        }  
        return res;  
    }  
};

// 2nd solution (Time Complexity: )
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.length; i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
}
}
};
