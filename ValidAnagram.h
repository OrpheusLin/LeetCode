/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-07 15:40
 Timing:     00:06:30
 Update:     2016-04-07 15:40
 Problem:    Valid Anagram
 Difficulty: Easy
 Source:     https://leetcode.com/problems/valid-anagram/
 Description:
 
 Given two strings s and t, write a function to determine if t is an anagram of s.
 
 Input:
 [anagram]
 [nagaram]
 
 Output:
 true
 
 Input:
 [rat]
 [cat]
 
 Output:
 false
 
 Input:
 []
 []
 
 Output:
 true
 
 Note: 1) anagrams have the same length and should be consist of same words with same frequencies. 2) Two Empty String are equalvalent. 3) Standard C++ Syntax does not support a convient Unicode character solution, and here is the solution for ANSICII. To deal with Unicode case, please use Java instead.
 
 Solution:
 1. Solved by Sort. Time Complexity: O(nlgn), Space Complexity: No need to allocate new space.
 2. Solved by Count. Time Complexity: O(n), Space Complexity: O(n)
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        return isAnagram_sort(s, t);
        //return isAnagram_count(s, t);
    }
    
    bool isAnagram_sort(string s, string t){
        if(s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(!s.compare(t)) return true;
        return false;
    }
    
    bool isAnagram_count(string s, string t){
        if(s.length() != t.length()) return false;
        
        int alphabet[256] = {0};
        
        for(int i = 0; i < s.length(); i++){
            alphabet[(int)s[i]] += 1;
            alphabet[(int)t[i]] -= 1;
        }
        
        for(int i = 0; i < 256; i++){
            if(alphabet[i] != 0)
                return false;
        }
        
        return true;
    }
};