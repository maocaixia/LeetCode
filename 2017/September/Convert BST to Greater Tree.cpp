/*****************************************************************************
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original 
key plus sum of all keys greater than the original key in BST.
Example:
Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*****************************************************************************/
//MyCode has some questions.
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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        
        root->val += getRightValue(root->right);
        convertTree(root);
        
        return root;
    }
    void convertTree(TreeNode* root){
        if(root->right){
            root->right->val +=  getRightValue(root->right->right);
            convertTree(root->right);
        }
        
        if(root->left){
            root->left->val += root->val + getRightValue(root->left->right);
            convertTree(root->left);
        }
        
    }
    // the right value
    int getRightValue(TreeNode* root){
        if(!root) return 0;
        return (root->val + getRightValue(root->right) + getRightValue(root->left));
    }
};
/*******************************************************************************************************/
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
private:
    int cur_sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
    void travel(TreeNode* root){
        if(!root) return;
        if(root->right) travel(root->right);
        root->val = (cur_sum += root->val);
        if(root->left) travel(root->left);
    }
};




