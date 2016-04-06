/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-07 00:18
 Timing:     00:07:58
 Update:     2016-04-07 00:18
 Problem:    Reverse Linked List
 Difficulty: Easy
 Source:     https://leetcode.com/problems/reverse-linked-list/
 Description:
 
 Reverse a singly linked list.
 
 Input:
 [1,2,3,4,5]
 
 Output:
 [5,4,3,2,1]
 
 Note: 1) A linked list can be reversed either iteratively or recursively. 2) There are two kinds of linked list. One is with Head Node, the other is without Head Node. Leetcode chose the latter data structure.
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
public:
    ListNode* reverseList(ListNode* head) {
        if(head != NULL)
            head = reverseListRecursive(head, NULL);
        return head;
    }
    
    ListNode* reverseListRecursive(ListNode* cur, ListNode* pre){
        ListNode* head;
        if(cur->next != NULL)
            head = reverseListRecursive(cur->next, cur);
        else
            head = cur;
        
        cur->next = pre;
        return head;
    }
};