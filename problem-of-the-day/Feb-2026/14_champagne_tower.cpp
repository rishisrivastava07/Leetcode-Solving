class Solution {
public:
    double t[101][101];

    double solve(int poured, int i, int j){
        if(i < j || i < 0 || j < 0) return 0.0;
        if(i == 0 && j == 0){
            return t[i][j] = poured;
        }
        
        if(t[i][j] != -1) return t[i][j];

        double left = max(0.0, (solve(poured, i-1, j-1) - 1)/2.0);
        double right = max(0.0, (solve(poured, i-1, j) - 1)/2.0);
        
        return t[i][j] = left + right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                t[i][j] = -1;
            }   
        }
        int i = query_row;
        int j = query_glass;

        return min(1.0, solve(poured, i, j));
    }
};