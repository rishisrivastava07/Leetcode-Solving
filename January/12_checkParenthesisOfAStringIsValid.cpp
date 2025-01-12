class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n % 2 != 0) return false;

        // Approach - 01 with extra space
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
    
        // Approach - 02 without extra space
        int openCount = 0, closeCount = 0;
        // for open brackets
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || locked[i] == '0'){
                openCount += 1;
            } else openCount -= 1;

            if(openCount < 0) return false;
        }

        // for close brackets
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ')' || locked[i] == '0'){
                closeCount += 1;
            } else closeCount -= 1;

            if(closeCount < 0) return false;
        }

        return true;
    }
};