/***************************************************************************
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
***************************************************************************/
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            double sum_layer = 0;
            for(int i=0; i<len; i++){
                TreeNode* p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right)q.push(p->right);
                sum_layer += p->val;
            }
            sum_layer /= len;
            res.push_back(sum_layer);
        }
        return res;
    }
};
