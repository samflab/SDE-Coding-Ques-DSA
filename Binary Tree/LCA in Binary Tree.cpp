/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” */
//CODE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root -> val == p -> val || root -> val == q -> val)
            return root;
        
        TreeNode *leftNode = lowestCommonAncestor(root -> left, p, q);
        TreeNode *rightNode = lowestCommonAncestor(root -> right, p, q);
        
        if(leftNode && rightNode)
            return root;
        if(leftNode)
            return leftNode;
        else
            return rightNode;
    }
};
