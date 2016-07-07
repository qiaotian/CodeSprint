/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-07T20:38:08+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-07T21:26:30+08:00
* @Inc: Goole, Uber
* @Difficulty: Medium
*/



You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
Return: [1,2],[1,4],[1,6]
The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
Return: [1,1],[1,1]
The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3
Return: [1,3],[2,3]
All possible pairs are returned from the sequence:
[1,3],[2,3]


class Solution {
public:
    // mycompare既可以定义在solution内，也可以定义在类外
    struct mycompare{
        bool operator()(pair<int, int>& p1, pair<int, int>&p2) {
            return p1.first+p1.second<p2.first+p2.second;
        }
    }; //一定要加分号

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;

        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(pq.size()<k) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                } else if(nums1[i]+nums[j]<pq.top().first+pq.top().second) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
