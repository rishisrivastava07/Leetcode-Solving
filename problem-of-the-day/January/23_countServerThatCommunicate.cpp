class Solution {
public:

    // Brute Force Approach
    // TC : O(n * m) + O(n + m)
    // SC : O(1)
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    bool isTrue = 0;

                    for(int col = 0; col < m; col++){
                        if(j != col && grid[i][col] == 1) isTrue = 1;
                    }

                    if(isTrue) count++;
                    else {
                        for(int row = 0; row < n; row++){
                            if(i != row && grid[row][j] == 1) isTrue = 1;
                        }

                        if(isTrue) count++;
                    }
                }
            }
        }

        return count;
    }

    // Approach - 02 
    // TC : O(n * m)
    // SC : O(n + m)
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    rowCount[i] += 1;
                    colCount[j] += 1;
                }
            }
        }


        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) count++;
            }
        }

        return count;
    }
};