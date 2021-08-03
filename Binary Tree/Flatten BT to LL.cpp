/* Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree. */

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
    void flatten(TreeNode* root) {
        TreeNode* tmp=root;
        stack<TreeNode*> st;
        while(root)
        {
            if(root->left)
            {
                if(root->right)
                {
                    st.push(root->right);
                }
                root->right=root->left;
                root->left=NULL;
            }
            if(root->right)
                root=root->right;
            else if(!st.empty())
            {
                root->right=st.top();
                st.pop();
                root=root->right;
            }
            else
                root=root->right;
        }
    }
};
