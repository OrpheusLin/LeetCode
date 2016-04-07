//
//  InvertBinaryTree.cpp
//  LeetCode
//
//  Created by LinOrpheus on 16/4/7.
//  Copyright (c) 2016年 LinOrpheus. All rights reserved.
//


/*
 Author:     Orpheus, orpheuslhy@yahoo.com
 Date:       2016-04-07 20:00
 Timing:     00:01:30
 Update:     2016-04-07 20:00
 Problem:    Invert Binary Tree
 Difficulty: Easy
 Source:     https://leetcode.com/problems/invert-binary-tree/
 Description:
 
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Input:
 [15,5,3,12,10,6,null,7,null,13l,16,null,20,18,13]
 
 Output:
 [15,3,5,null,6,10,12,20,null,16,13,null,7,null,null,null,null,null,null,13,18]
 
 Input:
 [1,null,2,3]
 
 Output:
 [1,2,null,null,3]
 
 Input:
 []
 
 Output:
 []
 */

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        if(root->left == NULL && root->right == NULL) return root;
        
        if(root->left != NULL)
            invertTree(root->left);
        if(root->right != NULL)
            invertTree(root->right);
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};
