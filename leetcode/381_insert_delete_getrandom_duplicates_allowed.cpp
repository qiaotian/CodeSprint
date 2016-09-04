/*
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
*/

class RandomizedCollection {
private:
    vector<int> nums;
	// unordered_map<int, vector<int>> mmap;
    unordered_multimap<int, int> pcmap;
public:
    /** Initialize your data structure here. */
    RandomizedCollection()  {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        int count = pcmap.count(val);
        pcmap.insert(std::make_pair(val, nums.size() - 1));
        return count == 0;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter = pcmap.find(val);
        if (iter == pcmap.end())
            return false;
        
        int pos = iter->second;
        pcmap.erase(iter, std::next(iter));
        
        int lastVal = nums.back();
        nums[pos] = lastVal;
        
        // Special case in consideration: remove the last inserted value (count: 0->1)
        for (auto iterLast = pcmap.find(lastVal); iterLast != pcmap.end(); iterLast++) {
            if (iterLast->second == nums.size() - 1) {
                pcmap.erase(iterLast, std::next(iterLast));
                pcmap.insert(std::make_pair(lastVal, pos));
                break; // break early to avoid meaningless loops
            }  
        } 
        
        nums.pop_back();  // pop last 
       
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand() % nums.size();
        return nums[pos];
    }
};
