/**********************************************************
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number 
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers 
for which this process ends in 1 are happy numbers.
Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
**********************************************************/

int next(int mm){
    int sum = 0;
    while(mm){
        sum += pow(mm%10,2);
        mm /= 10;
    }
    return sum;
}
class Solution {
public:
    bool isHappy(int n) {
        int fast = n, late = n;
        do{
            fast = next(fast);
            late = next(next(late));
        }while(fast != late);
        
        return fast == 1;
    }
};

/**************************************************************/
class Solution {
public:
    int tran(int n){
        int ans = 0;
        while(n){
            ans += pow(n%10, 2);
			n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        bool rep[1000];
        memset(rep, 0, sizeof(rep));
		n = tran(n);
        while(!rep[n]){
			rep[n] = true;
            if(n == 1)
                return true;   
			n = tran(n);
        }
        return false;
    }
};

