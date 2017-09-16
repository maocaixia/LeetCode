/**************************************
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*************************************/
class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        int count = 0;
        if(len == 1) return true;
        for(int i=1; i<len; i++){
            if(word[0] >= 'A' && word[0] <= 'Z'){
                if(word[i] >= 'A' && word[i] <= 'Z')
                    count += 2;
                else
                    count += 1;
            }
            else{
                if(word[i] >= 'A' && word[i] <= 'Z')
                    return false;
            }
        }
        return (count == 0) || (count == 2*(len-1)) || (count == len-1);
    }
};

