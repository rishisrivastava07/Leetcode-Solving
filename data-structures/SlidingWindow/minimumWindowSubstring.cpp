#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m > n) return "";

        unordered_map<char, int> mp;
        for(char& ch : t){
            mp[ch-'a']++;
        }
        int requiredCount = m;
        int windowSize = INT_MAX;
        int i = 0, j = 0;

        int start_i = 0;
        while(j < n){
            char ch = s[j];
            if(mp[ch -'a'] > 0) requiredCount--;
            mp[ch-'a']--;

            while(requiredCount == 0){
                int currWindowSize = j - i + 1;
                if(windowSize > currWindowSize){
                    windowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]-'a']++;
                if(mp[s[i]-'a'] > 0) requiredCount++;
                i++;
            }
            j++;
        }

        return windowSize == INT_MAX ? "" : s.substr(start_i, windowSize);
    }
};

int main(){
    /*
        Example 1:

        Input: s = "ADOBECODEBANC", t = "ABC"
        Output: "BANC"
        Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
        Example 2:

        Input: s = "a", t = "a"
        Output: "a"
        Explanation: The entire string s is the minimum window.
        Example 3:

        Input: s = "a", t = "aa"
        Output: ""
        Explanation: Both 'a's from t must be included in the window.
        Since the largest window of s only has one 'a', return empty string.
        

        Constraints:

        m == s.length
        n == t.length
        1 <= m, n <= 105
        s and t consist of uppercase and lowercase English letters.
        

        Follow up: Could you find an algorithm that runs in O(m + n) time?
    */    
    return 0;
}