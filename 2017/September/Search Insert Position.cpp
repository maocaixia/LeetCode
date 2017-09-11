/******************************************************************************
Given a sorted array and a target value, return the index if the target is found. If not, return the index 
where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
******************************************************************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(nums[0] > target)
            return 0;
        
        if(nums[nums.size()-1] < target) 
            return nums.size();
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < target) continue;
            else{
                if(nums[i] == target) 
                    return i;
                else
                    return i;
            }
        }
        
    }
};
