/****************************************************************************************
Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
****************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        TreePaths(res,root,to_string(root->val));
        return res;
    }
    void TreePaths(vector<string>& res, TreeNode* root, string t){
        if(!root->left && !root->right){
            res.push_back(t);
            return;
        }
        if(root->left)  TreePaths(res, root->left, t + "->" + to_string(root->left->val));
        if(root->right) TreePaths(res, root->right,t + "->" + to_string(root->right->val));
    }
};

