class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n == k) return true;
        if(n < k) return false;
        
        vector<int> countFreqs(26, 0);
        for(int i = 0; i < n; i++){
            countFreqs[s[i] - 'a']++;
        }

        int oddFreq = 0;
        for(int& freq : countFreqs){
            if(freq % 2 != 0) oddFreq++;
        }

        return oddFreq <= k;
    }
};