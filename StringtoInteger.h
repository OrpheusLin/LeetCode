/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-08 18:40
 Timing:     00:20:16
 Update:     2016-04-08 18:40
 Problem:    String to Integer(atoi)
 Difficulty: Easy
 Source:     https://leetcode.com/problems/string-to-integer-atoi/
 Description:
 
 Implement atoi to convert a string to an integer.
 
 Input:
 "123"
 
 Output:
 123
 
 Input:
 "12a13"
 
 Output:
 12
 
 Input:
 " -12.13   "
 
 Output:
 -12
 
 Input:
 "abc"
 
 Output:
 0
 
 Input:
 "-"
 
 Output:
 0
 
*/

class Solution {
public:
    string& trim(string& str){
        if(str.empty()) return str;
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        return str;
    }
    
    int myAtoi(string str) {
        if(str.empty()) return 0;
        
        str = trim(str);
        int len = str.length();
        
        if(len == 1 && (str[0] == '+' || str[1] == '-')){
            return 0;
        }
        
        int sign = 0;
        if(str[0] == '+'){
            sign = 1;
        }else if(str[0] == '-'){
            sign = -1;
        }
        
        int tot = (sign == 0)? 0 : 1;
        if(sign == 0){
            sign = 1;
        }
        
        long res = 0;
        while(tot < len){
            char c = str[tot];
            
            if(!isdigit(c)){
                return (int)res * sign;
            }
            
            res = 10 * res + (c - '0');
            
            if(res * sign > INT32_MAX){
                return INT32_MAX;
            }
            
            if(res * sign < INT32_MIN){
                return INT32_MIN;
            }
            
            tot++;
        }
        
        return (int)res * sign;
    }
};