/**********************************************************
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
******************************************************************************************/
//My Code
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int num;
        int len = nums.size();
        while(k--){
            
            num = nums[len-1];
            
            for(int i=len-1; i>0; i--){    
                nums[i] = nums[i-1];
            }    
            
            nums[0] = num;
            
        }
        
    }
};
/******************************************************************************************/
/******************************************************************************************/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int len = nums.size();
        
        if(len == 0 || k <= 0) 
            return;
        
        vector<int> num_cp(len);
        
        for(int i=0; i<len; i++){
            num_cp[i] = nums[i];
        }
        
        for(int j=0; j<len; j++){
            nums[(j+k)%len] = num_cp[j];
        }
        
    }
};
/******************************************************************************************/
/******************************************************************************************/
class Solution 
{
    public:
        void rotate(int nums[], int n, int k) 
        {
            k = k%n;
    
            // Reverse the first n - k numbers.
            // Index i (0 <= i < n - k) becomes n - k - i.
            reverse(nums, nums + n - k);
            
            // Reverse tha last k numbers.
            // Index n - k + i (0 <= i < k) becomes n - i.
            reverse(nums + n - k, nums + n);
            
            // Reverse all the numbers.
            // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
            // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
            reverse(nums, nums + n);
        }
};
