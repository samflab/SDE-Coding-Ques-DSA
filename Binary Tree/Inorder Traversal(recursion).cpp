class Solution {
public:
     vector<int> ans;
     vector<int> preorderTraversal(TreeNode* root) {
         if(root==NULL)return ans;
		
         preorderTraversal(root->left);
         ans.push_back(root->val);
         preorderTraversal(root->right);
         return ans;
     }
}; 
