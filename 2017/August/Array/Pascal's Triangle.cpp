/*******************************************************************************************
Pascal's Triangle:
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*******************************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Tri(numRows);
        for(int i=0; i<numRows; i++){
            Tri[i].resize(i+1);
            Tri[i][0] = Tri[i][i] = 1;
            for(int j=1; j<i; j++){
                Tri[i][j] = Tri[i-1][j-1] + Tri[i-1][j];
            }
        }
        return Tri;
    }
};
/*******************************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(auto i=0;i<numRows;++i)
        {
            res.push_back(vector<int>(i+1,1));
            for(auto j=1; j<i; ++j) res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};
