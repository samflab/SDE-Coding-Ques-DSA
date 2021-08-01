/* Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1. */
//CODE

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
    int checkBalance = 1;
    int getHeight(TreeNode *root){
        if(!root)
            return 0;
        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);
        if(abs(leftHeight - rightHeight) > 1){
           checkBalance = 0;
        }
         return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        checkBalance = 1;
        getHeight(root);
        return checkBalance;
    }
};
