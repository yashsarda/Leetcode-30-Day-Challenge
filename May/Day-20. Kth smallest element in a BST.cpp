/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
/*
Since it's a BST, the inorder traversal of BST is a sorted array.
We can use some extra space, store the inorder traversal of the BST in an array and to get the kth
smallest element use A[k - 1]

But the other approach would be to do inorder traversal, keeping a variable for counting which element this is. As soon as our counter reaches k, 
that element will be the answer

To reduce runtime complexity, we can make it balanced. 
For balanced tree, the height is O(log N)


Follow up ? No idea(s)

*/

void inorder(TreeNode* root, int& counter, int& answer, int k)
{
    if(!root || answer != 0)
        return;
    
    inorder(root -> left, counter, answer, k);
    
    counter++;
    if(counter == k)
        answer = root -> val;
    
    inorder(root -> right, counter, answer, k);
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int answer = 0;
        int counter = 0;
        
        inorder(root, counter, answer, k);
        
        return answer;
    }
};