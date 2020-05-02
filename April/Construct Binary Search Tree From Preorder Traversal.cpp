/*
Return the root node of a binary search tree that matches the given preorder traversal.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
*/
class Solution {
public:
    TreeNode* convert_to_bst(vector<int>& preorder, int start, int end)
    {
        if(start > end)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[start]);
        
        if(start == end)
            return root;
        
        int change_index = start;
        for(int i = start + 1; i <= end; i++) {
            if(preorder[i] > preorder[start]) {
                change_index = i;
                break;
            }
        }
        
        if(change_index == start)
            change_index = end + 1;
        root -> left = convert_to_bst(preorder, start + 1, change_index - 1);
        root -> right = convert_to_bst(preorder, change_index, end);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        if(n == 1) {
            return new TreeNode(preorder[0]);
        }
        
        TreeNode* root = convert_to_bst(preorder, 0, n - 1);
        
        return root;
    }
};