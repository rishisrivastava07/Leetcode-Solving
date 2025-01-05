class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> impact(n, 0);

        for(vector<int>& shift : shifts){
            int st = shift[0];
            int en = shift[1];
            int dir = shift[2];
            int x;
            
            if(dir == 0) x = -1;
            else x = 1;

            impact[st] += x;
            if(en+1 < n) impact[en+1] -= x;
        }

        // cummulative sum
        for(int i = 1; i < n; i++){
            impact[i] = impact[i] + impact[i-1];
        }

        for(int i = 0; i < n; i++){
            int shift = impact[i] % 26;
            if(impact[i] < 0) shift += 26;

            int value = s[i] - 'a';
            s[i] = ((value + shift) % 26) + 'a';  
        }

        return s;
    }
};