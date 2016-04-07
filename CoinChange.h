/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-07 16:30
 Timing:     00:04:30
 Update:     2016-04-07 15:30
 Problem:    Coin Change
 Difficulty: Medium
 Source:     https://leetcode.com/problems/coin-change/
 Description:
 
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Note:
 You may assume that you have an infinite number of each kind of coin.
 
 Input:
 [1,2,5]
 11
 
 Output:
 3
 
 Input:
 [2]
 3
 
 Output:
 -1
 
 Input:
 [2]
 4
 
 Output:
 2
 
 Note: greedy algorithm can not ensure possible solutions. E.X.: [2,3,5] 11 possible solution: 3. can not solved by greedy algorithm, but can be solved by DP.
 
 Solution:
 Dynamic Programming. Time Complexity: O(n^2), Space Complexity: O(n)
 */

#define MAX 65536
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> result;
        for(int i = 0; i <= amount; i++)
            result.push_back(MAX);
        result[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(coins[j] <= i && (result[i-coins[j]] + 1 < result[i]))
                    result[i] = result[i-coins[j]] + 1;
            }
        }
        return result[amount] == MAX? -1 : result[amount];
    }
};