// C++ program for Quick Sort on Singly Linled List
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    //ListNode(){}
    ListNode(int x):val(x), next(NULL){}
};

/* A utility function to insert a node at the beginning of linked list */
// 修改指针，如果不返回的话，需要使用指针的"引用"或二"级指针"
// 因为传进来的ListNode* head, 本质上是真正头指针的副本
void push(ListNode** head, int data) {
    ListNode *node = new ListNode(data);

    /* link the old list off the new node */
    node->next = (*head);

    /* move the head to point to the new node */
    (*head) = node;
}

/* A utility function to print linked list */
void printList(ListNode *node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Returns the last node of the list
ListNode *getTail(ListNode *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot
ListNode *partition(ListNode *head, ListNode *end,
                       ListNode **newHead, ListNode **newEnd)
{
    // 不仅要返回新链表头指针
    // 返回新链表头指针 newHead
    // 返回新链表头指针 newEnd
    ListNode *pivot = end;
    ListNode *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->val < pivot->val) {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev) prev->next = cur->next;
            ListNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL) (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}


//here the sorting happens exclusive of the end node
// 返回新链表头指针
ListNode *quickSortRecur(ListNode *head, ListNode *end)
{
    // base condition
    if (!head || head == end) return head;

    ListNode *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    ListNode *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        ListNode *tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;

        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(ListNode **head)
{
    (*head) = quickSortRecur(*head, getTail(*head));
    return;
}

// Driver program to test above functions
int main()
{
    ListNode *head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    cout << "Linked List before sorting \n";
    printList(head);

    quickSort(&head);

    cout << "Linked List after sorting \n";
    printList(head);

    return 0;
}
