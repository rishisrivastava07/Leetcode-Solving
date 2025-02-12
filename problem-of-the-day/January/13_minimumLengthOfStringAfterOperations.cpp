class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        int ans = s.length();   // initialise with total length
        
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;     // set the count of each character in string
            if(mp[s[i]] > 2){   // check if the count exceeds the 2 then it have 2 occurance on both sides
                mp[s[i]] = 1;   // reduce it to one after removing from both sides
                ans -= 2;   // subtract the 2 count from initial length of the string
            }
        }
        return ans;
    }
};