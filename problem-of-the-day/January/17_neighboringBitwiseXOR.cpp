class Solution {
public:
    // Approach 01 
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n);

        // let assume original[0] = 0;
        original[0] = 0;
        for(int i = 1; i < n; i++){
            original[i] = original[i-1] ^ derived[i-1];
        }

        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        // let assume original[0] = 1;
        original[0] = 1;
        for(int i = 1; i < n; i++){
            original[i] = original[i-1] ^ derived[i-1];
        }

        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        return false;
    }

    // Approach 02
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        int result = 0;
        for(int bit = 0; bit < n; bit++){
            result ^= derived[bit];
        }

        return result == 0 ? true : false;
    }
};