/**
* @Author: Tian Qiao
* @Date:   2016-07-03T15:27:55+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T16:35:43+08:00
* @Inc: LinkedIn
* @Difficulty: Easy
* @Tags: Data Structure Design
*/



Design and implement a TwoSum class. It should support the following operations: add and find.
add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

________________________________________________________________________________

//TLE
/*
class TwoSum {
public:
    unordered_map<int,int> hashmap; // map from number to count
    // Add the number to an internal data structure.
	void add(int number) {
	    if(hashmap.find(number)!=hashmap.end()){
	        hashmap[number]++;
	    } else {
	        hashmap.insert({number, 1});
	    }
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto i:hashmap){
	        if(hashmap.find(value-i.first)!=hashmap.end()) {
	            if(value-i.first!=i.first) return true;
	            if(hashmap[i.first]>1) return true; // i.first + i.first == value
	        }
	    }
	    return false;
	}
};
*/

// solution 1 稍作修改
class TwoSum {
public:
    unordered_map<int,int> hashmap; // map from number to count
    // Add the number to an internal data structure.
	void add(int number) {
	    //if(hashmap.find(number)!=hashmap.end()){
	        hashmap[number]++;
	    //} else {
	    //    hashmap.insert({number, 1});
	    //}
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto i:hashmap){
	        if(hashmap.find(value-i.first)!=hashmap.end()) {
	            if(value-i.first!=i.first) return true;
	            if(hashmap[i.first]>1) return true; // i.first + i.first == value
	        }
	    }
	    return false;
	}
};

/*
class TwoSum {
    unordered_multiset<int> nums;
public:
    void add(int number) {
        nums.insert(number);
    }
    bool find(int value) {
        for (int i : nums) {
            int count = i == value - i ? 1 : 0;
            if (nums.count(value - i) > count) {
                return true;
            }
        }
        return false;
    }
};
*/

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
