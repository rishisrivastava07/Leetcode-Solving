/*
Problem Statement - 2840 : Check if Strings Can be Made Equal with Operations I.
You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

Example 1:

Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
Example 2:

Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
 

Constraints:

n == s1.length == s2.length
1 <= n <= 105
s1 and s2 consist only of lowercase English letters.
*/
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // check if the lengths of the strings are equal
        if (s1.length() != s2.length()) {
            return false;
        }

        // create two maps to store the characters at even and odd indices
        map<char, int> s1_even;
        map<char, int> s1_odd;
        map<char, int> s2_even;
        map<char, int> s2_odd;

        // iterate over the characters in the strings
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                // if the index is even, add the character to the even map
                s1_even[s1[i]]++;
                s2_even[s2[i]]++;
            } else {
                // if the index is odd, add the character to the odd map
                s1_odd[s1[i]]++;
                s2_odd[s2[i]]++;
            }
        }

        // check if the characters at even and odd indices are equal in both strings
        return s1_even == s2_even && s1_odd == s2_odd;
    }
};