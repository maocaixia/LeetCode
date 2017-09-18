/**************************************************************************
Count the number of prime numbers less than a non-negative number, n.
**************************************************************************/
//MyCode
bool IfPrime(int num){
    if(num == 2) return true; 
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0){
            return false;
        }
    }        
    return true;
}

class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        int count = 0;
        for(int i=2; i<n; i++){
            if(IfPrime(i))
                count++;
        }    
        return count;
    }
};
//Code2
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        prime[0] = prime[1] = false;
        for(int i=0; i<sqrt(n); i++){
            if(prime[i]){
                for(int j=i*i; j<n; j+=i){
                    prime[j] = false;
                }
            }
        }
        return count(prime.begin(),prime.end(),true);
    }
};

