/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-06 21:00
 Timing:     00:05:30
 Update:     2016-04-06 21:00
 Problem:    Two Sum
 Difficulty: Easy
 Source:     https://leetcode.com/problems/two-sum/
 Description:
 
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 You may assume that each input would have exactly one solution.
 
 Input:
 [2, 7, 11, 15]
 9
 
 Output:
 [0, 1].
 
 UPDATE (2016/2/13):
 The return format had been changed to zero-based indices. Please read the above updated description carefully.
 
 Solution:
 1. Sort + Scan. Time Complexity: O(nlgn) Space Complexity: O(n)
 2. Hash. Time Complexity: O(n) Space Complexity: O(n)
 */

#include "TwoSum_Hash.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {};
        if(nums.size() == 0) return result;
        unordered_map<int, int> hash;
        int num;
        for(int i = 0; i < nums.size(); i++){
            num = target - nums[i];
            if(hash.find(num) != hash.end()){
                result.push_back(hash[num]);
                result.push_back(i);
                return result;
            }else{
                hash[nums[i]] = i;
            }
        }
        return result;
    }
};