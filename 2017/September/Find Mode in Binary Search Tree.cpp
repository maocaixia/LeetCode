/*************************************************************************
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].
*************************************************************************/
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
    vector<int> modes;  
    vector<int> findMode(TreeNode* root) {
        //vector<int> modes;  
        int mfq/*max freq*/, pre/*previous val*/, cnt/*duplicates count*/;
        getMaxFreq(root, mfq=0, pre, cnt=0); // in-order traversal to get max frequency
        getMode(root, mfq, pre, cnt=0);      // in-order traversal to get all modes
        return modes;
    }
    void getMaxFreq(TreeNode* r, int& mfq, int& pre, int& cnt) {
      if (!r) return;
      getMaxFreq(r->left, mfq, pre, cnt);
      getMaxFreq(r->right, mfq=max(mfq,cnt), pre=r->val, ++(cnt*=(r->val==pre)));
    }
    
    void getMode(TreeNode* r, const int mfq, int& pre, int& cnt) {
      if (!r) return;
      getMode(r->left, mfq, pre, cnt);
      if (mfq == ++(cnt*=(r->val==pre))) modes.push_back(r->val);
      getMode(r->right, mfq, pre=r->val, cnt);
    }
};
/*********************************************************************************************/
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> res;
        int modeCount = getModeCount(root, map);
        for(pair<int, int> p : map){
            if(p.second == modeCount){
                res.push_back(p.first);
            }
        }
        return res;
    }
    int getModeCount(TreeNode* root, unordered_map<int, int> &map){
        if(root == NULL) return 0;
        
        if(map.find(root->val) == map.end()){
            map.insert(pair<int, int>(root->val, 1));
        }
        else{
            map[root->val]++;
        }
        
        return max(map[root->val], max(getModeCount(root->left, map), getModeCount(root->right, map)));
    }
};

