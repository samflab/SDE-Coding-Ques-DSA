/* Given the root of a binary tree, return the inorder traversal of its nodes' values. */
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;        //integer vector
        stack<TreeNode*> nodes; //stack of type TreeNode
        while(root != NULL || !nodes.empty()){      //till root is not null OR stack is not empty
            if(root != NULL){
                nodes.push(root);   //push root to stack
                root = root -> left;    //root will point to left
            }
            else{
                root = nodes.top(); //after node becomes null, stack's top is pointing to root
                nodes.pop();        //top node will be popped
                res.push_back(root->val);   //that root's val will be pushed
                root = root -> right;   //root points to right
            }
        }
        
        return res;
    }
};
