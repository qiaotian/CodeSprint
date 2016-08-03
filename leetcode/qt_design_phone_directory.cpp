/**
* @Author: Tian Qiao
* @Date:   2016-08-03T15:28:29+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-03T15:28:34+08:00
* @Tag: List, Design
*/

/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/


// 使用unordered_set超时
// 需要使用整数数组
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    //unordered_set<int> avail;
    //int capacity = 0;
    vector<int> freelist; // store the available and unavailable elements
    vector<bool> flaglist; // mark the number is available or not
    int index;     // point to first available elements, all elements store before index have been used
    PhoneDirectory(int maxNumbers) {
        freelist.resize(maxNumbers, 0);
        flaglist.resize(maxNumbers, true);

        index = 0;

        for(int i=0; i<maxNumbers; i++) freelist[i] = i;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(index<freelist.size()) {
            flaglist[freelist[index]] = false;
            return freelist[index++];
        } else {
            return -1;
        }
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return number>=0 && number<freelist.size() && flaglist[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if(number>=0 && number<freelist.size() && !flaglist[number]) {
            flaglist[number] = true;
            freelist[--index] = number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
