/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * My solution
 * k可能很大，如果不考虑组间优化，很容易超时
 * 应当尽量减小k。两两合并，使用队列
 * Time: beats:98%
 */
/*
class Solution {
public:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* tmp1 = list1;
        ListNode* tmp2 = list2;

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(tmp1 && tmp2) {
            if(!head) {
                if(tmp1->val < tmp2->val) {
                    head = tmp1;
                    tail = head;
                    tmp1 = tmp1->next;
                    tail->next = NULL;
                } else {
                    head = tmp2;
                    tail = head;
                    tmp2 = tmp2->next;
                    tail->next = NULL;
                }
            }
            else {
                if(tmp1->val < tmp2->val) {
                    tail->next = tmp1;
                    tmp1 = tmp1->next;
                    tail = tail->next;
                    tail->next = NULL;
                } else {
                    tail->next = tmp2;
                    tmp2 = tmp2->next;
                    tail = tail->next;
                    tail->next = NULL;
                }
            }
        }

        if(tmp1) tail->next = tmp1;
        if(tmp2) tail->next = tmp2;

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];

        queue<ListNode*> que;
        for(auto i:lists) {
            que.push(i);
        }

        while(que.size()>1) {
            ListNode* list1 = que.front();
            que.pop();
            ListNode* list2 = que.front();
            que.pop();
            ListNode* mergeList = merge2Lists(list1, list2);
            que.push(mergeList);
        }

        //ListNode* head = NULL;
        //for (auto i:lists) {
        //    head = merge2Lists(head, i);
        //}
        return que.front();
    }
};
*/

/**
 * 使用优先队列
 * beats 12%
 */
/*
class Solution {
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
public:
ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    for(auto l : lists) {
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    ListNode* result = q.top();
    q.pop();
    if(result->next) q.push(result->next);
    ListNode* tail = result;
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next) q.push(tail->next);
    }
    return result;
}
};
*/

/**
 * 使用heap
 * beats: 12%
 */
class Solution {
    static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
public:
ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode*> v;
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        pop_heap(v.begin(), v.end(), heapComp);
        v.pop_back();
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next);
            push_heap(v.begin(), v.end(), heapComp);
        }
    }
    return head.next;
}
};
/**
 * 渣算法
 */
/*
class Solution {
public:
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin()); // vector.erase具有O(N)复杂度
        lists.erase(lists.begin()); //
    }
    return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
};
*/
