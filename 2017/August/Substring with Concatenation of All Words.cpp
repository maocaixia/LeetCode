/******************* 
     Map容器的介绍  
********************
http://blog.csdn.net/gubenpeiyuan/article/details/9613979
/**********************
      问题描述
**********************
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) 
in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*************************
       解答
*************************
I think the following code is self-explanatory enough. We use an unordered_map<string, int> counts to record the expected times 
of each word and another unordered_map<string, int> seen to record the times we have seen. Then we check for every possible 
position of i. Once we meet an unexpected word or the times of some word is larger than its expected times, we stop the check. 
If we finish the check successfully, push i to the result indexes.
******************************
******************************/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> counts;
        vector<int> indexs;
        for(string word:words)
            counts[word]++;
        int n = s.length(),num = words.size(),len = words[0].length();
        for(int i=0; i<n-num*len+1; i++){
            int j = 0;
            map<string,int> seen;
            for(; j<num; j++){
                string word = s.substr(i+j*len,len);
                //unordered_map<string,int> seen;
                if(counts.find(word) != counts.end()){
                    seen[word]++;
                    if(seen[word]>counts[word])
                        break;
                }
                else break;
            }
            if(j == num) indexs.push_back(i);
        }
        return indexs;
    }
};
