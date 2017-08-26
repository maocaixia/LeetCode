Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
===================================================================================================================================
1\top-down:
int minimumTotal(vector<vector<int>>& triangle){
  vector<int> res(triangle.size(),triangle[0][0]);
  for(int i=1; i<triangle.size(); i++){
    for(int j=i; j>=0; j--){
      if(j == 0) 
        res[0] += triangle[i][j];
      else if(j == i)
        res[j] = triangle[i][j] + res[j-1];
      else
        res[j] = triangle[i][j] + min(res[j],res[j-1]);
    }
  }
  return *min_element(res.begin(),res.end());
}
===================================================================================================================================
2\bottom-up
int minimumTotal(vector<vector<int>>& triangle){
  vector<int> res = triangle.back(); //'triangle.back()' means 'triangle[triangle.size()-1];'
  for(int i=triangle.size()-2; i>=0; i--){
    for(int j=0; j<=i; j++){
      res[j] = triangle[i][j] + min(res[j],res[j+1]);
    }
  }
  return res[0];
}
