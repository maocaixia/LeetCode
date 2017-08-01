/*********************
      问题描述
**********************
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
**********************
reverse()用法
http://imyon.github.io/cpp/2014/01/11/c++-reverse()%E5%87%BD%E6%95%B0%E7%9A%84%E7%94%A8%E6%B3%95
**********************
      问题解答
**********************
**********************/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                k = i;
                break;
            }
        }
        if(k == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] > nums[k]){
                swap(nums[i],nums[k]);
                break;
            }
        }
        reverse(nums.begin()+k+1,nums.end());
    }
};
