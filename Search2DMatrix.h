/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-08 10:30
 Timing:     00:02:25
 Update:     2016-04-08 10:30
 Problem:    Search a 2D Matrix
 Difficulty: Medium
 Source:     https://leetcode.com/problems/search-a-2d-matrix/
 Description:
 
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 
 Input:
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 
 Output:
 3
 
 Solution:
 1. searching + prunning: search the matrix, compare the target with the top-right element in the sub-matrix iteratively so as to skip at least one row or one column which doesn't contain a possible solution, we can reduce the searching space effectively.
 Time Complexity: O(m+n), or O(max{m,n}) Space Complexity: O(1)
 2. divide and conquer: compare the target with the middle element in the sub-matrix, and we can skip a sub-matrix which doesn't contain a possible solution.
 T(N) = T(N/2) + T(N/4) + O(1)
 Time Complexity: O(N^0.5) ~ O(N) Space Complexity: O(1)
 */

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        return searchMatrix_1(matrix, target);
        //return searchMatrix_2(matrix, target);
    }
    
    bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i = 0, j = col-1; (i < row) && (j >= 0);){
            if(matrix[i][j] < target)
                i++;
            else if(matrix[i][j] > target)
                j--;
            else
                return true;
        }
        
        return false;
    }
    
    bool find(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2, int target){
        if(x1 > x2 || y1 > y2) return false;
        
        int midx = (x1+x2) >> 1;
        int midy = (y1+y2) >> 1;
        
        if(matrix[midx][midy] == target) return true;
        
        return (target < matrix[midx][midy])?
        (find(matrix, x1, y1, midx-1, y2, target) || find(matrix, midx, y1, x2, midy-1, target)) :
        (find(matrix, x1, midy+1, x2, y2, target) || find(matrix, midx+1, y1, x2, midy, target));
    }
    
    bool searchMatrix_2(vector<vector<int>> & matrix, int target){
        int row = matrix.size();
        int col = matrix[0].size();
        return find(matrix, 0, 0, row-1, col-1, target);
    }
};