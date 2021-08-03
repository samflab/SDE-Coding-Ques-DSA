/* Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value. */
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    //both null, then identical
            return true;
        else if(!p || !q)   //if either of them is null, then not identical
            return false;
        else if(p -> val != q -> val)   //if values are different then return false
            return false;
        //traverse the entire tree at left and right, if identical, returns true
        else{
            return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        }
    }
};
