class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        // step 1 - find sum of array
        long long totalShifts = accumulate(shifts.begin(), shifts.end(), 0LL);
        string result = s;

        // step 2 - Iterate and shift the letters
        for(int i = 0; i < n; i++){
            result[i] = (result[i] - 'a' + totalShifts) % 26 + 'a';
            totalShifts -= shifts[i];
        }

        return result;
    }
};