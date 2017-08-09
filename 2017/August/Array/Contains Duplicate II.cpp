/************************************************************************************************
Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
******************************************************************************************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> nmap;
        for (int i = 0; i <nums.size();i++)
        {
            if (nmap.count(nums[i]) == 0)
                nmap[nums[i]] = i;
            else if (i - nmap[nums[i]] <=k)
                return true;
            else
                nmap[nums[i]] = i;
        }
        return false;
    }
};

