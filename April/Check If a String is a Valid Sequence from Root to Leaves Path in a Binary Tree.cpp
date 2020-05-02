/*
Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a 
sequence in the given binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int n;
    bool checkValid(TreeNode* root, int index, vector<int>& arr)
    {
        if(!root)
            return false;
        
        if(index == n - 1) {
            if(!root -> left && !root -> right)
               return (root -> val == arr.back()); 
            return false;
        }
        
        if(root -> val != arr[index])
            return false;
       
        return (checkValid(root -> left, index + 1, arr) || checkValid(root -> right, index + 1, arr)); 
        
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n = arr.size();
        if(!root && !n)
            return true;
        
        bool answer = checkValid(root, 0, arr);
        return answer;
    }
};