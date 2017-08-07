/********************************
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep 
its original data.
You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the
row number and column number of the wanted reshaped matrix, respectively.
The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the 
original matrix.
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
****************************************
Code
******************************************/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        //if(nums.empty()) return NULL;
        int n = nums.size(), m = nums[0].size(); 
        if(n*m != r*c) return nums;
        vector<vector<int>> res(r,vector<int>(c,0));
        for(int i=0; i<n*m; i++){
            res[i/c][i%c] = nums[i/m][i%m];
        }
        return res;
    }
};
