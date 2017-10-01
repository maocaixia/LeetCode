/**************************************************************
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST 
such that their sum is equal to the given target. Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9
Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
Output: False
**************************************************************/
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return dfs(root, set, k);
    }
    bool dfs(TreeNode* root, unordered_set<int>& set, int k){
        if(!root) return false;
        if(set.count(k-root->val)) return true;
        set.insert(root->val);
        return dfs(root->left,set,k) || dfs(root->right,set,k);
    }
};
/***************************************************************************/
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> num;
        inorder(root, num);
        for(int i=0, j=num.size()-1; i<j;){
            if(num[i]+num[j] == k) return true;
            (num[i]+num[j]<k) ? i++ : j--;
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int>& num){
        if(!root) return;
        inorder(root->left, num);
        num.push_back(root->val);
        inorder(root->right,num);
    }
};
/***************************************************************************/
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
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
    bool dfs(TreeNode* root, TreeNode*cur, int k){
        if(cur == NULL) return false;
        return search(root, cur, k-cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
    }
    bool search(TreeNode* root, TreeNode* cur, int value){
        if(root == NULL) return false;
        return (root->val == value) && (root != cur) 
            || (root->val < value) && search(root->right, cur, value)
                ||(root->val > value) && search(root->left, cur,value);
    }
};
