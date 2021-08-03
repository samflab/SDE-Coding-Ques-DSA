/* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center). */
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return isSymmetricSame(root -> left, root -> right);
    }
    bool isSymmetricSame(TreeNode *left, TreeNode *right){
      if(!left || !right)
          return left == right;
    
        if(left -> val != right -> val){
            return false;
        }
        
        return isSymmetricSame(left -> left, right -> right) && isSymmetricSame(left -> right, right -> left);
    }
    
    
};
