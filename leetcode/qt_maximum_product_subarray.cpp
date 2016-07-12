/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T10:25:53+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T14:17:21+08:00
*/



/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    //如果出现0，需要将数组分成两个子数组
    int helper(vector<int>& nums, int start, int end) {
        if(start==end) return nums[start];
        if(start >end) return INT32_MIN;

        vector<long long> product(nums.size(), 1);
        vector<int> count(nums.size(), 0);

        long long maxproduct = INT32_MIN;

        for(int i=start; i<=end; i++) {
            if(nums[i]==0) {
                // 求解子数组
                return max(0, max(helper(nums, start, i-1), helper(nums, i+1, end)));
            } else if(nums[i] < 0) {
                count[i] = i==start?1:(count[i-1]+1);
                product[i] = i==start?nums[i]:(product[i-1]*nums[i]);
            } else {
                count[i] = i==start?0:(count[i-1]);
                product[i] = i==start?nums[i]:(product[i-1]*nums[i]);
            }
        }
        int ll = start;
        int rr = end;
        while(ll<=rr) {
            if((count[rr]-count[ll]+(nums[ll]<0?1:0))%2) {
                rr--;
            } else {
                maxproduct = max(maxproduct, product[rr]/product[ll]*nums[ll]);
                break;
            }
        }
        ll = start;
        rr = end;
        while(ll<=rr) {
            if((count[rr]-count[ll]+(nums[ll]<0))%2) ll++;
            else {
                maxproduct = max(maxproduct, product[rr]/product[ll]*nums[ll]);
                break;
            }
        }
        return (int)maxproduct;
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return helper(nums, 0, (int)nums.size()-1);
    }
};

class Solution2 {
 public:
    int maxProduct(vector<int>& nums) {
    	int frontProduct = 1;
    	int backProduct = 1;
  		int ans = INT32_MIN;
  		for (int i = 0; i < nums.size(); ++i) {
  			frontProduct *= nums[i];
  			backProduct *= nums[nums.size() - i - 1];
  			ans = max(ans,max(frontProduct,backProduct));
            // 一旦遇到0，将product置初始化为1，重新计算
  		    frontProduct = frontProduct == 0 ? 1 : frontProduct;
  		    backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-2, -3};
    Solution1 *sln = new Solution1();
    int a = sln->maxProduct(nums);
    cout << a << endl;
    return a;
}
