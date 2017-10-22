// nums中只有一个值出现超过1次，其余出现且仅出现一次
// 首先还是想到hash，但是提示要求只能用O(1) extra space
// The main idea is the same with problem Linked List Cycle II,https://leetcode.com/problems/linked-list-cycle-ii/.
// Use two pointers the fast and the slow. The fast one goes forward two steps each time, while the slow one goes only step each time. They must meet the same item when slow==fast. In fact, they meet in a circle, the duplicate number must be the entry point of the circle when visiting the array from nums[0]. Next we just need to find the entry point. We use a point(we can use the fast one before) to visit form begining with one step each time, do the same job to slow. When fast==slow, they meet at the entry point of the circle. The easy understood code is as follows.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return -1;

        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/**
 * 证明过程如下
When they meet, assume slow tag move s steps, fast tag move 2s steps, the circle length is c. There must be:
            2s = s + n*c
         => s = n*c....(1)
Then, assume the length from start point to entry point is x, and the length from the entry point to the meet point is a. There must be: s = x+a....(2)
So, from (1) and (2)
            x+a = s = n*c
         => x+a = n*c
         => x+a = (n-1)*c+c
         => x = (n-1)*c+c-a
c-a means the length from the meetpoint to the entry point.
LHS means: the new tag from start point move x steps.
RHS means: the slow tag moves (n-1) cycles plus the length from the meetpoint to the entry point.
 * /
