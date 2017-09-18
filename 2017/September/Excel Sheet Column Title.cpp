/*****************************************************************
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
***************************************************************/
//Code1
class Solution {
public:
    string convertToTitle(int n) {
        return (n == 0) ? "" : convertToTitle(n/26) + (char)(--n % 26 + 'A');
    }
};
//Code2
class Solution {
public:
string convertToTitle(int n) {

    string res;

    char tmp;

    while(n){

        n -= 1;

        tmp = 'A' + n % 26;

        res = tmp + res;

        n /= 26;

    }

    return res;

}
};


