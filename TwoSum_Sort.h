/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-06 14:30
 Timing:     00:23:26
 Update:     2016-04-06 14:30
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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumPair{
public:
    int value;
    int index;
    NumPair(int value, int index){
        this->value = value;
        this->index = index;
    }
};

bool compare(NumPair p1, NumPair p2){
    return p1.value < p2.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() == 0) return result;
        
        vector<NumPair> pairArr;
        for(int i = 0; i < nums.size(); i++){
            NumPair p(nums.at(i), i);
            pairArr.push_back(p);
        }
        sort(pairArr.begin(), pairArr.end(), compare);
        
        int left = 0;
        int right = (int)(pairArr.size() - 1);
        int sum = 0;
        while(left < right){
            sum = pairArr.at(left).value + pairArr.at(right).value;
            if(sum == target){
                result.push_back(pairArr.at(left).index);
                result.push_back(pairArr.at(right).index);
                return result;
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
        
        return result;
    }
};
