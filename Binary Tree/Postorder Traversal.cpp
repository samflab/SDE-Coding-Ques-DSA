/* Given the root of a binary tree, return the postorder traversal of its nodes' values. */
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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> postOrder;
        if (root == NULL)
            return postOrder;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            postOrder.insert(postOrder.begin(), curr->val);
            if (curr->left != NULL)
                stack.push(curr->left);
            if (curr->right != NULL)
                stack.push(curr->right);
        }
        return postOrder;
    }
};
