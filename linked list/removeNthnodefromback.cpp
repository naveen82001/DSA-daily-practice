#include <bits/stdc++.h>
using namespace std;

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == NULL)
            return NULL;

        ListNode *ptr1 = head;
        ListNode *ptr2 = head;

        for (int i = 0; i < n; i++)
        {
            if (ptr2->next == NULL)
            {
                if (i != n - 1)
                    return head;

                head = head->next;
                return head;
            }
            ptr2 = ptr2->next;
        }

        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        ptr1->next = ptr1->next->next;

        return head;
    }
};