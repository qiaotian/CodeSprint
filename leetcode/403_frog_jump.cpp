/*
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
*/




// BackTracking, TLE
class Solution {
    unordered_map<int, int> hashmap;
public:
    bool util(vector<int>& stones, int pos, int k) {
        if(pos==stones.size()-1) return true;
        
        auto search = hashmap.find(stones[pos]+k+1);
        if(  1 && search!=hashmap.end() && util(stones, search->second, k+1)) return true;
        search = hashmap.find(stones[pos]+k);
        if(k>0 && search!=hashmap.end() && util(stones, search->second, k)) return true;
        search = hashmap.find(stones[pos]+k-1);
        if(k>1 && search!=hashmap.end() && util(stones, search->second, k-1)) return true;
        return false;
    }
    bool canCross(vector<int>& stones) {
        for(int i=0; i<stones.size(); i++) hashmap[stones[i]] = i;
        return util(stones, 0, 0);
    }
};

// 改进BackTracking:不适用hashmap
class Solution {
    bool help(vector<int>& stones,int start,int k){
        if (start==stones.size()-1) return true;
        for (int i=start+1;i<stones.size();i++){
            if (stones[i]-stones[start]<k-1) continue;
            if (stones[i]-stones[start]>k+1) return false;
            if (help(stones,i,stones[i]-stones[start])) return true;
        }   
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones.size()<=1) return 1;
        int start = 0,k = 0;   // k is the steps when jumping to current stone.
        return help(stones,start,k);
    }
}


// DP


