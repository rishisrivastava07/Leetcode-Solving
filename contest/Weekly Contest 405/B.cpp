/*
Problem Statement - 3211 : Generate Binary Strings without Adjacent Zeros
You are given a positive integer n.

A binary string x is valid if all 
substrings
 of x of length 2 contain at least one "1".

Return all valid strings with length n, in any order.

 

Example 1:

Input: n = 3

Output: ["010","011","101","110","111"]

Explanation:

The valid strings of length 3 are: "010", "011", "101", "110", and "111".

Example 2:

Input: n = 1

Output: ["0","1"]

Explanation:

The valid strings of length 1 are: "0" and "1".

 

Constraints:

1 <= n <= 18
*/


class Solution {
    void validSubStrings(int n, vector<string> &ans, string subStr){
        // if the current string length is equals to n size 
        // then we get an ans store it in ans vector
        if(subStr.length() == n){
            ans.push_back(subStr);
            return;
        }

        // call for the next char with 1
        validSubStrings(n, ans, subStr + "1");

        // and if the char of first and last of substring is not 0
        // then call for the s + '0' one
        if(subStr.empty() || subStr.back() != '0'){
            validSubStrings(n, ans, subStr + '0');
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        
        validSubStrings(n, ans, "");
        // as we get the list of subsrtings in opposite order
        // reverse the vector<string>
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};