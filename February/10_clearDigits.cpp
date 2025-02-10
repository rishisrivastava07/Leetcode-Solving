class Solution {
public:
    string clearDigits(string s) {
        while (true) {
            bool flag = false;
            for (int i = 0; i < s.length(); ++i) {
                if(isdigit(s[i])) {
                    flag = true;
                    for (int j = i - 1; j >= 0; --j) {
                        if (!isdigit(s[j])) {
                            s.erase(i, 1);
                            s.erase(j, 1);
                            break;
                        }
                    }
                    break;
                }
            }
            if (!flag) break;
        }
        return s;
    }
};