#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAllZero(vector<int>& counter){
        return counter == vector<int>(26, 0);
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = s.length();
        int m = p.length();
        
        // Count the pattern characters and store it in counter
        vector<int> counter(26, 0);
        for(char& ch : p){
            counter[ch - 'a']++;
        }

        // Take two pointers initialised to 0 for sliding window
        int i = 0, j = 0;
        while(j < n){
            // for each character at j decrease it by 1
            counter[s[j] - 'a']--;
            // As soon the window length is equal to pattern string length
            // check for all zero in counter if true store index of 'i' in result
            if(j - i + 1 == m){
                if(isAllZero(counter)) result.push_back(i);

                // Reset the count by increasing the character occurance by 1
                counter[s[i] - 'a']++;
                // Shrink the Window size by i++;
                i++;
            }
            j++;
        }
        return result;
    }
};

int main(){
    /*
        Input: s = "cbaebabacd", p = "abc"
        Output: [0,6]
        Explanation:
        The substring with start index = 0 is "cba", which is an anagram of "abc".
        The substring with start index = 6 is "bac", which is an anagram of "abc".
    */
    return 0;
}