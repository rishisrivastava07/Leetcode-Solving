class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        
        set<int> st;
        int repeating = -1, missing = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(st.count(grid[i][j]) > 0){
                    repeating = grid[i][j];
                } else {
                    st.insert(grid[i][j]);
                }
            }
        }

        int i = 1;
        auto first = st.begin();
        while(!st.empty() || i <= n*n){
            if(*first != i){
                missing = i; 
                break;
            }
            (first)++;
            i++;
        }
        return {repeating, missing};
    }
};