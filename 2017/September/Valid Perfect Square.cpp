/************************************************************************************
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.
Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
************************************************************************************/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        for(int i=1; i<=num/2; i++){
            if(i*i == num) return true;
        }
        return false;
    }
};
/*******************************************************************************************/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 0, r = num;
        while(l <= r){
            long mid = (l+r) >> 1;
            long sqmid = mid * mid;
            if(sqmid > num) r = mid -1;
            else if(sqmid < num) l = mid + 1;
            else return true;
        }
        return false;
    }
};
/******************************************************************************************/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long r = 1;
        while(r * r < num) r <<= 1;
        long l = r >> 1;
        while(l < r){
            long mid = (l + r) >> 1;
            if(mid * mid >= num) r = mid;
            else l = mid + 1;
        }
        return r * r == num;
    }
};


