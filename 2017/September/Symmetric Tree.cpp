/*******************************************************************************************
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
******************************************************************************************/
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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> l;
        stack<TreeNode*> r;
        if(root == NULL) return true;
        if(root->left)  l.push(root->left);
        if(root->right) r.push(root->right);
        
        while(!l.empty() && !r.empty()){
            TreeNode* cur_l = l.top();
            TreeNode* cur_r = r.top();
            
            l.pop();
            r.pop();
            
            if(cur_l->val != cur_r->val) return false;
            
            if(cur_l->left)  l.push(cur_l->left);
            if(cur_r->right) r.push(cur_r->right);
            if(l.size() != r.size()) return false;
            
            if(cur_l->right) l.push(cur_l->right);
            if(cur_r->left)  r.push(cur_r->left);
            if(l.size() != r.size()) return false;            
        }
        return l.size() == r.size();
    }
};
/***********************************************************************************************************/
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->right);
    }
    bool helper(TreeNode* p, TreeNode* q){
        if(!q && !p) return true;
        else if(!q || !p) return false;
        
        if(p->val != q->val) return false;
        
        return helper(p->left,q->right) && helper(p->right,q->left);
    }
};


