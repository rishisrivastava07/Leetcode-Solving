class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        int counter = 1;
        stack<char> st;

        string num = "";

        for(int i = 0; i <= n; i++){
            st.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I'){
                while(!st.empty()){
                    num.push_back(st.top());
                    st.pop();
                }
            }
        }

        return num;
    }
};