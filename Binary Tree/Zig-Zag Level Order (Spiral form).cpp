/* Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).*/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root == NULL)
            return ans;
        q.push(root);       //push root to queue
        int f = 1;          //level toggle integer
        while(!q.empty()){
            vector<int> temp;   //temp vector
            int size = q.size();    //size of queue
            
            while(size--){
                TreeNode *t = q.front();    //t node points to queue
                temp.push_back(t -> val);  //  push t's val to the temp vector
                q.pop();
                if(t -> left)
                    q.push(t -> left);  //if left sub tree exists, push to queue
                if(t -> right)
                    q.push(t -> right);
            }
            if(f % 2 == 0)
                reverse(temp.begin(), temp.end());      //if at an even level, reverse the temp vector
            ans.push_back(temp);
            f = !f;             //if f = 0, make it 1 and vice versa
            
        }
        return ans;
    }
};
