/******************************************************************************
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. 
And you need to output the maximum average value.
Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*****************************************************************************/
//MyCode
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int len = nums.size();
        int res = INT_MIN;
        for(int i=0; i<=len-k; i++){
            int sum = 0;
            for(int j=i; j<k+i; j++){
                sum += nums[j];
            }
            if(sum > res)
                res = sum;
        }
        return (double)res/k;
    }
};
/**********************************************************************************/
Simple Code
/**********************************************************************************/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxsum = INT_MIN;
        int sum = 0;
        // k = min((size_t)k, nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i - k];
            }
            if (i >= k - 1) {
                maxsum = max(maxsum, sum);            
            }
        }
        return (double)maxsum / k;
    }
};
