/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
*/

class Solution {
    int global_answer = INT_MIN;
public:
    int findMaximumSum(TreeNode* root)
    {
        if(!root)
            return 0;
        if(!root -> left && !root -> right) {
            global_answer = max(global_answer, root -> val);
            return root -> val;
        }

        int leftSum = findMaximumSum(root -> left);
        int rightSum = findMaximumSum(root -> right);
        
        int answer = 0;
        answer = root -> val + max(leftSum, rightSum);
        answer = max(answer, root -> val);
        
        global_answer = max(answer, max(root -> val + leftSum + rightSum, global_answer));
        
        return answer;
        
    }
    int maxPathSum(TreeNode* root) {
        int answer = findMaximumSum(root);
        return global_answer;
    }
};