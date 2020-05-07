/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
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
    void level_order_traversal(TreeNode* root, queue<TreeNode*> q, int& parentt, int& depth, int search)
    {
        q.push(root);
        map<TreeNode*, int> d;
        d[root] = 0;
        while(!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();
            if(parent -> left) {
                if(parent -> left -> val == search) {
                    parentt = parent -> val;
                    depth = d[parent] + 1;
                    return;
                }
                q.push(parent -> left);
                d[parent -> left] = d[parent] + 1;
            }
            if(parent -> right) {
                 if(parent -> right -> val == search) {
                    parentt = parent -> val;
                    depth = d[parent] + 1;
                    return;
                }
                q.push(parent -> right);
                d[parent -> right] = d[parent] + 1;
            }
            
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        int parent1 = -1, parent2 = -1;
        int depth1 = -1, depth2 = -1;
        level_order_traversal(root, q, parent1, depth1, x);
        level_order_traversal(root, q, parent2, depth2, y);
        
        return (depth1 == depth2 && parent1 != parent2);
    }
};