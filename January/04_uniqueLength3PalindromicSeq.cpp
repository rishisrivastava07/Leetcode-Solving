class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        // store unique elements
        unordered_set<char> letters;
        for(char ch : s) letters.insert(ch);

        int result = 0;

        // give each letter a chance of forming palindrome
        for(char letter : letters){
            int left_idx = -1;
            int right_idx = -1;

            // find left and right ends
            for(int i = 0; i < n; i++){
                if(s[i] == letter){
                    if(left_idx == -1) left_idx = i;
                    right_idx = i;
                }
            }

            // counting the size of plaindrome
            unordered_set<char> st;
            for(int i = left_idx+1; i <= right_idx-1; i++){
                st.insert(s[i]);
            }

            // add each possible palindrome to result
            result += st.size();
        } 

        return result;
    }
};