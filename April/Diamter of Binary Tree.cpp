/*
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int answer = 0;
    
    int findDiameter(TreeNode root)
    {
        if(root == null)
            return 0;
        if(root -> left == null && root -> right == null)
            return 1;
        
        int leftSubtree = findDiameter(root -> left);
        int rightSubtree = findDiameter(root -> right);
        
        answer = max(answer, Math.max(leftSubtree, rightSubtree));
        
        answer = max(answer, leftSubtree + rightSubtree);
        
        return 1 + Math.max(leftSubtree, rightSubtree);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null)
            return 0;
        
        if(root -> left == null && root -> right == null)
            return 0;
        
        findDiameter(root);
        return answer;
    }
}