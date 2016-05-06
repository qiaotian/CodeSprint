// use heap
/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> cnt;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        for(auto i : nums) cnt[i]++;

        for(auto i : cnt) {
            pq.push({i.second, i.first});
            while(pq.size()>k) pq.pop();
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};*/

// use bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> cnt;

        for(auto num : nums) cnt[num]++;

        vector<vector<int>> bucket(nums.size() + 1); // 桶
        for (auto pair : cnt) {
            bucket[pair.second].push_back(pair.first); // 按照出现次数分桶
        }

        // 按出现次数由高到低
        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                ans.push_back(bucket[i][j]);
                if (ans.size() == k) return ans; // 找到出现频率最高的k个数
            }
        }

        return ans;
    }
};
