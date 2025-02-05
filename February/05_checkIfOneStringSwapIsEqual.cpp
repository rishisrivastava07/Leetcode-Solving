class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.size();
        vector<int> diff;
        
        // Find the indices where s1 and s2 differ
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
                if (diff.size() > 2) return false; // More than two mismatches means it can't be made equal by a single swap
            }
        }
        
        // If exactly two differences exist, check if swapping makes them equal
        return diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};
