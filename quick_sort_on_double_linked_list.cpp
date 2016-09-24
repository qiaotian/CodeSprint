/*
Ive been making a number of standard classes for my own future developments and one of them was a linked list class. I wanted a method to sort the list but not using the slow bubble sort. I wanted the speed of quick sort, but there wasnt a qsort run time function for linked lists. So I hunted down the quick sort algorithm and applied it to my linked list class.

Anyway, I wanted to give something useful to COTD, so I quickly wrote the code below to show you how its done. I haven't compared the function to a quick sort function using an array, so I don't know how fast it is.

*/

// Quick Sort on a Linked List
// By Stephen Hassall
// Web: www.logic22.com
// EMail: stephen@logic22.com

#include <stdio.h>

// Define a linked list structure
typedef struct ListNode
{
    // The integer object
    int nInteger;

    // Pointers
    struct ListNode *pPrev;
    struct ListNode *pNext;
} ListNode;

// Pointers to First and Last items
ListNode *g_pFirstItem = NULL;
ListNode *g_pLastItem = NULL;

// Add List Item
void AddListItem(int nInteger)
{
    // Create a new list item
    ListNode *pItem = new ListNode;

    // Set Integer value
    pItem->nInteger = nInteger;

    // Add to list
    // If this is the first item added
    if (g_pFirstItem == NULL)
    {
        g_pFirstItem = g_pLastItem = pItem;
        pItem->pNext = pItem->pPrev = NULL;
    }
    else
    {
        // Add item to the end of the list
        g_pLastItem->pNext = pItem;
        pItem->pPrev = g_pLastItem;
        g_pLastItem = pItem;
        pItem->pNext = NULL;
    }
}

// Remove all items
void RemoveAllItems()
{
    ListNode *pDelItem, *pItem = g_pFirstItem;

    // Loop while there are items
    while (pItem != NULL)
    {
        // Set the delete item
        pDelItem = pItem;

        // Move to the next item
        pItem = pItem->pNext;

        // Delete the item
        delete pDelItem;
    }

    // Set global pointers to NULL
    g_pFirstItem = g_pLastItem = NULL;
}

// Print List
void PrintList()
{
    ListNode *pItem = g_pFirstItem;

    // Loop while there are items
    while (pItem != NULL)
    {
        // Print this item
        printf("%d\n", pItem->nInteger);

        // Move to the next item
        pItem = pItem->pNext;
    }
}

// Quick Sort List
void QuickSortList(ListNode *pLeft, ListNode *pRight)
{
    ListNode *pStart;
    ListNode *pCurrent;
    int nCopyInteger;

    // If the left and right pointers are the same, then return
    if (pLeft == pRight) return;

    // Set the Start and the Current item pointers
    pStart = pLeft;
    pCurrent = pStart->pNext;

    // Loop forever (well until we get to the right)
    while (1)
    {
        // If the start item is less then the right
        if (pStart->nInteger < pCurrent->nInteger)
        {
            // Swap the items
            nCopyInteger = pCurrent->nInteger;
            pCurrent->nInteger = pStart->nInteger;
            pStart->nInteger = nCopyInteger;
        }

        // Check if we have reached the right end
        if (pCurrent == pRight) break;

        // Move to the next item in the list
        pCurrent = pCurrent->pNext;
    }

    // Swap the First and Current items
    nCopyInteger = pLeft->nInteger;
    pLeft->nInteger = pCurrent->nInteger;
    pCurrent->nInteger = nCopyInteger;

    // Save this Current item
    ListNode *pOldCurrent = pCurrent;

    // Check if we need to sort the left hand size of the Current point
    pCurrent = pCurrent->pPrev;
    if (pCurrent != NULL)
    {
        if ((pLeft->pPrev != pCurrent) && (pCurrent->pNext != pLeft))
            QuickSortList(pLeft, pCurrent);
    }

    // Check if we need to sort the right hand size of the Current point
    pCurrent = pOldCurrent;
    pCurrent = pCurrent->pNext;
    if (pCurrent != NULL)
    {
        if ((pCurrent->pPrev != pRight) && (pRight->pNext != pCurrent))
            QuickSortList(pCurrent, pRight);
    }
}

// Main
void main ()
{
    // Add some items
    AddListItem(100);
    AddListItem(12);
    AddListItem(56);
    AddListItem(67);
    AddListItem(4);
    AddListItem(91);
    AddListItem(34);
    AddListItem(59);
    AddListItem(42);
    AddListItem(20);
    AddListItem(83);
    AddListItem(74);
    AddListItem(33);
    AddListItem(79);
    AddListItem(49);
    AddListItem(51);

    // Sort the list
    QuickSortList(g_pFirstItem, g_pLastItem);

    // Print list
    PrintList();

    // Remove items from list
    RemoveAllItems();
}
