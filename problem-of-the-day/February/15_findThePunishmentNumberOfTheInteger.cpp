class Solution {
public:
    bool check(string s, int num, int i, int currSum){
        if(i == s.length()) return currSum == num;
        if(currSum > num) return false;

        bool isPossible = false;
        for(int j = i; j < s.length(); j++){
            string ss = s.substr(i, j-i+1);
            int ss_num = stoi(ss);

            isPossible = isPossible || check(s, num, j+1, currSum + ss_num);
            if(isPossible == true) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punish = 0;

        for(int num = 1; num <= n; num++){
            int sq = num * num;
            string s = to_string(sq);

            if(check(s, num, 0, 0) == true) punish += sq;
        }

        return punish;
    }
};