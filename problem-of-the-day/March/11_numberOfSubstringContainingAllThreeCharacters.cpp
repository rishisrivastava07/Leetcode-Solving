class Solution {
    public:
        bool isValid(vector<int>& count){
            for(int& cnt : count){
                if(cnt == 0) return false;
            }
    
            return true;
        }
    
        int numberOfSubstrings(string s) {
            int n = s.size();
            
            int result = 0;
            vector<int> count(3, 0);
            int i = 0, j = 0;
            while(j < n){
                count[s[j] - 'a'] += 1;
    
                while(isValid(count)){
                    // valid substring
                    result += (n-j);
                    count[s[i] - 'a'] -= 1;
                    i++;
                }
                
                j++;
            }
    
            return result;
        }
    };