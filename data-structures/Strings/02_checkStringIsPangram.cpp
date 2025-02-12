#include<bits/stdc++.h>
using namespace std;

// A pangram is a sentence where every letter of the English alphabet appears at least once.
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Store the count of each letter in english alphabhet
        vector<int> lettersCount(26, 0);

        for(char& ch : sentence){
            lettersCount[ch-'a']++;
        }

        for(int& count : lettersCount){
            // If anyone of the letter count is less than 1 then return false
            if(count == 0) return false;
        }
        
        return true;
    }
};

int main(){
    // Driver Code 
    return 0;
}