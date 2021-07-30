/* Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 */
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root == NULL)
            return ans;
        
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.back()->val);
            while(size--){
                TreeNode *temp = q.front();
                q.pop();
                if(temp -> left)
                    q.push(temp->left);
                if(temp -> right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};
