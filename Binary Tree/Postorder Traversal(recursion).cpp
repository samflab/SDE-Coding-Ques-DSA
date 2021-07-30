class Solution {
public:
     vector<int> ans;
     vector<int> preorderTraversal(TreeNode* root) {
         if(root==NULL)return ans;
		 
         preorderTraversal(root->left);
         preorderTraversal(root->right);
         ans.push_back(root->val);
         return ans;
     }
}; 
