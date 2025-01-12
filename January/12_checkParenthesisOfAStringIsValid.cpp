class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n % 2 != 0) return false;

        stack<int> openStk;
        stack<int> openCloseStk;

        int i = 0;
        while(i < n){
            if(locked[i] == '0'){
                openCloseStk.push(i);
            } else if(s[i] == '(') {
                openStk.push(i);
            } else if(s[i] == ')'){
                if(!openStk.empty()){
                    openStk.pop();
                } else if(!openCloseStk.empty()){
                    openCloseStk.pop();
                } else return false;
            }
            i++;
        }

        while(!openStk.empty() && !openCloseStk.empty() && openStk.top() < openCloseStk.top()){
            openStk.pop();
            openCloseStk.pop();
        }

        return openStk.empty();
    }
};