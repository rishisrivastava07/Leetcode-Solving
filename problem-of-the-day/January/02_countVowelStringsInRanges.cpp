class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();

        vector<int> results(m, 0);
        vector<int> cummSum(n, 0);

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(vowels.find(words[i][0]) != vowels.end()){
                if(vowels.find(words[i][words[i].length()-1]) != vowels.end()){
                    sum++;
                }
            }
            cummSum[i] = sum;
        }

        for(int i = 0; i < m; i++){
            int st = queries[i][0];
            int en = queries[i][1];

            results[i] = cummSum[en] - ((st > 0) ? cummSum[st-1] : 0);
        }

        return results;
    }
};