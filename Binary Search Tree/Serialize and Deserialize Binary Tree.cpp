/* Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself. */

//CODE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode* makeTree(queue<string> &q) {
        string s = q.front();    //string has 1st value in queue
        q.pop();                   //remove the first value as it will be used in tree
        if(s=="null")
            return NULL;        //if it is null then add null
        TreeNode* root = new TreeNode(stoi(s));     //convert string to integer
        root->left = makeTree(q);                   //add to left subtree
        root->right = makeTree(q);                  //add to right subtree
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         if(!root)
            return "null,";         //if root is null, then add "null" to string
      return to_string(root->val)+","+ serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s ="";
        queue <string> q;
        for(char c: data) {
            if(c ==',') {       //removing all commas
                q.push(s);
                s="";
                continue;
            }
            s+=c;
        }
        return makeTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
