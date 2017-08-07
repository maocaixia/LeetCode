/************************
   Qusetion Describe
*************************
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*************************
 My  Answer(Time Limited Exceeded)
***************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max=-9999, index;
        int count = 0;
        if(nums.size()==1) return nums[0];
        for(int i=0; i<=nums.size()/2; i++){
            if(i>=1 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > max){
                max = count;
                index = i;
            }
            if(max > nums.size()/2)
                break;
            count = 0;
        }
        return nums[index];
    }
};
/*****************************************************
Another Answer
*********************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(++counts[nums[i]] > n/2)
                return nums[i];
        }
    }
};
