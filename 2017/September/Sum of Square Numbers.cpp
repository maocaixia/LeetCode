/*********************************************************************
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
********************************************************************/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);
        
        while(a <= b){
            if(a*a + b*b == c) return true;
            else if(a*a + b*b > c) b--;
            else a++;
        }
        return false;
    }
};

