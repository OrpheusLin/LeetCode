/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-08 11:00
 Timing:     00:02:25
 Update:     2016-04-08 11:00
 Problem:    Sort Colors
 Difficulty: Medium
 Source:     https://leetcode.com/problems/sort-colors/
 Description:
 
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
 Note:
 You are not suppose to use the library's sort function for this problem.
 
 The problem is known as Holland National Flag Problem.
 
 Input:
 [0,1,1,2,0,1,0,2,1,1,0,0,1]
 
 Output:
 [0,0,0,0,0,1,1,1,1,1,1,2,2]
 
 Solution:
 1. swapping based in loop invariance
 Time Complexity: O(n) Space Complexity: O(1)
 2. counting sort
 Time Complexity: O(n) Space Complexity: O(1)
 */

class Solution {
public:
    void sortColors_1(vector<int>& nums) {
        int i = 0, j = nums.size();
        for(int k = 0; k < j; ++k){
            if(nums[k] == 0)
                swap(nums[i++], nums[k]);
            else if(nums[k] == 2)
                swap(nums[--j], nums[k--]);
        }
    }
    
    void sortColors_2(vector<int>& nums) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        
        for(int i = 0; i < nums.size(); i++)
            nums[i] == 0? count0++ : (nums[i] == 1? count1++ : count2++);
        
        int tot = 0;
        for(; tot < count0; tot++)
            nums[tot] = 0;
        for(; tot < count0 + count1; tot++)
            nums[tot] = 1;
        for(; tot < count0 + count1 + count2; tot++)
            nums[tot] = 2;
    }
};