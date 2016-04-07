/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-07 18:30
 Timing:     00:02:25
 Update:     2016-04-07 18:30
 Problem:    Climbing Stairs
 Difficulty: Easy
 Source:     https://leetcode.com/problems/climbing-stairs/
 Description:
 
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Input:
 7
 
 Output:
 21
 
 Input:
 8
 
 Output:
 34
 */

class Solution {
public:
    int climbStairs(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++)
            result.push_back(0);
        
        result[0] = 0;
        result[1] = 1;
        result[2] = 2;
        for(int i = 3; i <= n; i++)
            result[i] = result[i-1] + result[i-2];
        
        return result[n];
    }
};