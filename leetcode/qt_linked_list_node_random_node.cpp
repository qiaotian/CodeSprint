
/* * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
class Solution {
private:
    vector<ListNode*> vec;
public:
    // @param head The linked list's head.
    //    Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode* tmp = head;
        while(tmp) {
            vec.push_back(tmp);
            tmp = tmp->next;
        }
    }
   
    // Returns a random node's value.
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx]->val;
    }
};
*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    vector<ListNode*> vec;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode* tmp = head;
        while(tmp) {
            vec.push_back(tmp);
            tmp = tmp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
