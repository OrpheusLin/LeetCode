/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-08 13:00
 Timing:     00:05:25
 Update:     2016-04-08 13:00
 Problem:    Longest Substring Without Repeating Characters
 Difficulty: Medium
 Source:     https://leetcode.com/problems/longest-substring-without-repeating-characters/
 Description:
 
 Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 
 Input:
 "abcabcbb"
 
 Output:
 3
 
 Input:
 "bbbbb"
 
 Output:
 1
 
 
 Solution:
 Sliding Window with two pointers
 Time Complexity: O(n) Space Complexity: O(n), a bool array to judge duplicate elements.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> dupChars(256, false);
        int maxLen = 0;
        for(int i = 0, j = 0;;i++){
            while((j < s.length()) && (dupChars[s[j]] != true)){
                dupChars[s[j++]] = true;
            }
            maxLen = max(maxLen, j-i);
            if(j >= s.length())
                break;
            while(s[i] != s[j]){
                dupChars[s[i++]] = false;
            }
            dupChars[s[i]] = false;
        }
        return maxLen;
    }
};
