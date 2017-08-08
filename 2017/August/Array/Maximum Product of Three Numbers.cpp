/**************************************
Given an integer array, find three numbers whose product is maximum and output the maximum product.
Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
************************************************************************************************
Summary:sort()函数用法
***********************************************************************************************
要使用此函数只需用#include <algorithm> sort即可使用，语法描述为：
sort(begin,end)，表示一个范围，例如：
int _tmain(int argc, _TCHAR* argv[])
{
 int a[20]={2,4,1,23,5,76,0,43,24,65},i;
 for(i=0;i<20;i++)
  cout<<a[i]<<endl;
 sort(a,a+20);
 for(i=0;i<20;i++)
 cout<<a[i]<<endl;
 return 0;
}
降序排序：一种是自己编写一个比较函数来实现，接着调用三个参数的sort：sort(begin,end,compare)就成了
1）自己编写compare函数：

bool compare(int a,int b)
{
      return a<b;   //升序排列，如果改为return a>b，则为降序

}

int _tmain(int argc, _TCHAR* argv[])
{
     int a[20]={2,4,1,23,5,76,0,43,24,65},i;
     for(i=0;i<20;i++)
       cout<<a[i]<<endl;
     sort(a,a+20,compare);
     for(i=0;i<20;i++)
       cout<<a[i]<<endl;
     return 0;
}
********************************************************************************************/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int num0 = nums[n-1] * nums[n-2] * nums[n-3];
        int num1 = nums[0] * nums[1] * nums[n-1];
        return num0 > num1 ? num0 : num1;
    }
};
