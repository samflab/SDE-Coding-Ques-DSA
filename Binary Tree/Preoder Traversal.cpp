/* Given the root of a binary tree, return the preorder traversal of its nodes' values.*/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node;
        
        while(root != NULL || !node.empty()){    //till root is not null OR stack is not empty
            if(root != NULL){
                result.push_back(root -> val);   //push root's value
                if(root -> right){               //right subtree
                    node.push(root -> right);     //push root's right's value
                }
                root = root -> left;    //left subtree
            }
            else{
                root = node.top();    //if root is null, left subtree is not present
                node.pop();
            }
            
        }
        
        return result;
        
    }
};
