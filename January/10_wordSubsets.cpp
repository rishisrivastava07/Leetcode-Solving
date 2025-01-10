class Solution {
public:
    bool isSubset(vector<int>& freq, vector<int>& temp){
        for(int i = 0; i < 26; i++){
            if(temp[i] < freq[i]) return false;
        }

        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();

        vector<string> result;

        vector<int> freq2(26, 0);
        for(string& word : words2){
            vector<int> temp(26, 0);

            for(char& ch : word){
                temp[ch - 'a']++;
                freq2[ch - 'a'] = max(temp[ch - 'a'], freq2[ch - 'a']);
            }
        }

        for(string& word : words1){
            vector<int> temp(26, 0);
            for(char& ch : word){
                temp[ch - 'a']++;
            }

            if(isSubset(freq2, temp) == true){
                result.push_back(word);
            }
        }

        return result;
    }
};