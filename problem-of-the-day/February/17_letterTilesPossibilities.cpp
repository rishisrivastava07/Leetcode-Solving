class Solution {
public:
    void solve(string &s, vector<bool>& isUsed, unordered_set<string>& result, string& curr){
        result.insert(curr);
        for(int i = 0; i < s.size(); i++){
            if(isUsed[i] ) continue;

            isUsed[i] = true;
            curr.push_back(s[i]);

            solve(s, isUsed, result, curr);

            isUsed[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> isUsed(n, false);
        unordered_set<string> result;

        string curr = "";
        solve(tiles, isUsed, result, curr);
        
        return result.size()-1;
    }
};