/********************************************************************************
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
**************************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int num = nums[0];
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            num = max(sum,num);
            sum = max(sum,0);
        }
        return num;
    }
};
