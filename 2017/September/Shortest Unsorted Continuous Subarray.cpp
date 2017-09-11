/***************************************************************
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.
Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*******************************************************************************************************************/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int shortlen = 0;
        int left = 0, right = nums.size()-1;
        
        while(nums[left] <= nums[left+1] && left < nums.size() - 1) left++;
        while(nums[right] >= nums[right-1] && right > 0)    right--;
        
        if(left < right){
            int max = INT_MIN, min = INT_MAX;
            for(int i=left; i<=right; i++){
                if(nums[i] > max) max = nums[i];
                if(nums[i] < min) min = nums[i];
            }
            
            while(nums[left-1] > min && left > 0)    left--;
            while(nums[right+1] < max && right < nums.size()-1)   right++;

            shortlen = right - left + 1;
        }
        
        
        
        return shortlen;
    }
};

