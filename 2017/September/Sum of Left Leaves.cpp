/*******************************************************
Find the sum of all left leaves in a given binary tree.
Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
**************************************************************************/
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        Sum_Tree(root, sum);
        return sum;
    }
    void Sum_Tree(TreeNode* root, int& sum){
        
        if(root->left) {
            if(!root->left->left && !root->left->right)
                {sum += root->left->val;}
            else {
                Sum_Tree(root->left, sum);
            }
        }
        
        if(root->right){
            if(!root->right->left && !root->right->right);
            else{
                Sum_Tree(root->right, sum);
            }
        }
    }
};
/***********************************************************************************/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

