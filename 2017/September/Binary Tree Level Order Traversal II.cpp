/******************************************************************************
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level 
from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*****************************************************************************/
//Mycode has some questions."reference binding to null pointer of type 'struct value_type'"
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //if(root == NULL) return NULL;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int Currlevel = 0;
        while(!q.empty()){
            for(int i=0, n=q.size(); i<n; i++){
                TreeNode* p = q.front();
                q.pop();
                res[Currlevel].push_back(p->val);
                if(p->left  != NULL)  q.push(p->left);
                if(p->right != NULL) q.push(p->right);
                
            }
            Currlevel++;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
/****************************************************************************************************/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(ans,root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void levelorder(vector<vector<int>> &ans, TreeNode* node, int level){
        if(!node) return;
        if(level >= ans.size()) ans.push_back({});
        
        ans[level].push_back(node->val);
        levelorder(ans,node->left,level+1);
        levelorder(ans,node->right,level+1);
    }
};
/*************************************************************************************/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> ans(d,vector<int>{});
        levelorder(ans,root,d-1);
        return ans;
    }
    
    int depth(TreeNode* root){
        if(!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    
    void levelorder(vector<vector<int>> &ans, TreeNode* node, int level){
        if(!node) return;
        ans[level].push_back(node->val);
        levelorder(ans,node->left,level-1);
        levelorder(ans,node->right,level-1);
    }
};
/*******************************************************************************************/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            vector<int> curlayer;
            for(int i=0; i<l; i++){
                TreeNode* cur = q.front();
                q.pop();
                curlayer.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            ret.push_back(curlayer);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};


