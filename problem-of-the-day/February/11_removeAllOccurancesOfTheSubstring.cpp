// Approach 01 
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int idx = s.find(part);
            if(idx == string::npos){
                break;
            }
            s.erase(idx, part.length());
        }

        return s;
    }
};

// Approach 02
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int m = part.length();

        for(char& ch : s){
            result.push_back(ch);
            
            if(result.length() >= m && result.substr(result.length() - m) == part){
                result.erase(result.length() - m);
            }
        }

        return result;
    }
};

// Approach - 03
class Solution {
public:
    bool check(int m, string part, stack<char>& st){
        stack<char> tempStack = st;

        for(int i = m-1; i >= 0; i--){
            if(tempStack.top() != part[i]){
                return false;
            }

            tempStack.pop();
        }

        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = part.length();
        int n = s.length();

        for(int i = 0; i < n; i++){
            st.push(s[i]);

            if(st.size() >= m && check(m, part, st) == true){
                for(int j = 0; j < m; j++){
                    st.pop();
                }
            }
        }

        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }
};