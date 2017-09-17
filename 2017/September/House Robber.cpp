/********************************************************************
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it 
will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
*********************************************************************/
//Code1
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int a = 0, b = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(i%2 == 0){
                a = max(a+nums[i],b);
            }
            
            else{
                b = max(b+nums[i],a);
            }
        }
        
        return max(a,b);
    }
};

//Code2
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> f(n, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i)
            f[i] = max(f[i-2] + nums[i], f[i-1]);
        return f[n-1];
    }
};

