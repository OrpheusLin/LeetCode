/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-07 13:03
 Timing:     00:26:23
 Update:     2016-04-07 13:03
 Problem:    Reverse Linked List II
 Difficulty: Medium
 Source:     https://leetcode.com/problems/reverse-linked-list-ii/
 Description:
 
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 
 Input:
 [1,2,3,4,5]
 2
 4
 
 Output:
 [1,4,3,2,5]
 
 Note: 1) There are two kinds of linked list. One is with Head Node, the other is without Head Node. Leetcode chose the latter data structure. 2) In order to design a general interface, I add a Empty Head Node to List without a Head Node.
 
 Solution: Time Complexity: O(n), Space Complexity: O(1)
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
    ListNode* reverseBetween(ListNode* head, int from, int to) {
        if(head == NULL) return NULL;
        
        ListNode *cursor = new ListNode(0);
        cursor->next = head;
        ListNode *pHead = cursor;
        ListNode *pPre, *pCur, *pNext;
        pCur = pHead->next;
        
        int cnt = 0;
        for(; cnt < from-1; cnt++){
            pHead = pCur;
            pCur = pCur->next;
        }
        
        pPre = pCur;
        pCur = pCur->next;
        to--;
        
        for(; cnt < to; cnt++){
            pNext = pCur->next;
            pCur->next = pHead->next;
            pHead->next = pCur;
            pPre->next = pNext;
            pCur = pNext;
        }
        
        if(from == 1) head = pHead->next;
        delete cursor;
        return head;
    }
    
};