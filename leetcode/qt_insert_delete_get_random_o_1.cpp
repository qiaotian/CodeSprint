/**
* @Author: Tian Qiao
* @Date:   2016-08-04T16:21:59+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-04T16:22:33+08:00
* @Difficulty: Medium
* @Inc: Google
*/

/*
Design a data structure that supports all following operations in O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
*/

// AC but not right
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> uset;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(uset.find(val)!=uset.end()) return false;
        uset.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(uset.find(val)==uset.end()) return false;
        uset.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return *uset.begin();
    }
};

// 2. Use a Hash Table and a Vector
// https://discuss.leetcode.com/topic/53200/c-solution-using-hashmap-and-vector-idea-sharing
class RandomizedSet {
private:
    vector<int> tmp;
    unordered_map<int, int> map;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        tmp.emplace_back(val);
        map[val] = tmp.size() - 1;
        return true;
    }

    /** Deletes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        int indx = map[val];
        tmp[indx] = tmp[tmp.size() - 1];
        map[tmp[indx]] = indx;
        tmp.pop_back();
        map.erase(map.find(val));
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return tmp[rand() % tmp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
