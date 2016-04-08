/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-08 18:40
 Timing:     00:20:00
 Update:     2016-04-08 18:40
 Problem:    Ugly Number II
 Difficulty: Medium
 Source:     https://leetcode.com/problems/ugly-number-ii/
 Description:
 
 Write a program to find the n-th ugly number.
 
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 
 Note that 1 is typically treated as an ugly number.
 
 Input:
 492
 
 Output:
 864000
 
 Input:
 1450
 
 Output:
 671088640
 
 Solution:
 Dynamic Programing. use 3 Queues to store multiples of 2,3,and 5. Every time we pick out the smallest in three queues as X, and use this number as the next ugly number generator. Then we remove the numbers which equals to X in 3 queues. Execute N times and we will get the Nth-Ugly Number.
 
 Notes: try to solve problems by iteratively checking numbers and call isUglyNum will cause a TLE error, even if you use a memo as an optimization.
 */

class Solution {
public:
    int nthUglyNumber(int n){
        if(n == 1) return 1;
        int next = 1;
        queue<int> nums_2, nums_3, nums_5;
        for(int i = 1; i < n; i++){
            nums_2.push(next * 2);
            nums_3.push(next * 3);
            nums_5.push(next * 5);
            
            next = min(nums_2.front(), min(nums_3.front(), nums_5.front()));
            
            if(next == nums_2.front())
                nums_2.pop();
            if(next == nums_3.front())
                nums_3.pop();
            if(next == nums_5.front())
                nums_5.pop();
        }
        return next;
    }
};