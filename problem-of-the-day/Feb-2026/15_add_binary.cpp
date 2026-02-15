class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        string ans;
        int carry = 0;
        
        while(i >= 0 || j >= 0){
            int sum = 0;
            if(i >= 0 && j >= 0){
                sum = carry + (a[i] - '0') + (b[j] - '0');
            } else if(i >= 0 && j < 0){
                sum = carry + (a[i] - '0');
            } else {
                sum = carry + (b[j] - '0');
            }
            carry = (sum > 1) ? 1 : 0;
            ans.push_back((sum % 2 == 0) ? '0' : '1');
            i--; j--;
        }
        
        if(carry){
            ans.push_back(carry + '0');
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};