/* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path. */
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
    int solve(TreeNode* root, int& res)
    {
        if(root == NULL)  //  Base Condition
            return 0;
        
        int left = solve(root->left, res); 
        int right = solve(root->right, res);

        int temp = max( max(left, right) + root->val , root->val );  
        int ans = max(temp, left + right + root->val);
        res = max(ans, res);

        return temp;
    }
    
    int maxPathSum(TreeNode* root) 
    {    
        int res = INT_MIN;
        solve(root, res);
        return res;
    }

    
    
};
