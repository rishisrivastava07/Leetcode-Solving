class Solution {
public:
    int ROW;
    int COL;

    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    bool DFS(int i, int j, vector<vector<int>> &grid){
        if(i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] == 1){
            return false;
        } 

        if(i == ROW-1) return true;
        grid[i][j] = 1;

        for(vector<int> &dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(DFS(i_, j_, grid) == true){
                return true;
            }
        }
        return false;
    }

    bool canCross(vector<vector<int>>& cells, int day){
        vector<vector<int>> grid(ROW, vector<int>(COL)); 

        // fill the land cells with water till current day
        for(int i = 0; i <= day; i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            grid[r][c] = 1;
        }    
        
        // Call DFS from the top row after filling lands with water till today
        for(int j = 0; j < COL; j++){
            if(grid[0][j] == 0 && DFS(0, j, grid) == true){
                return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;
        
        vector<vector<int>> grid(ROW, vector<int>(COL, 0)); 
        int n = cells.size();
        int st = 0;
        int en = n - 1;

        int lastDay = 0;

        while(st <= en){
            int mid = st + (en - st)/2;

            if(canCross(cells, mid)){
                lastDay = mid + 1;
                st = mid + 1;
            }
            else{
                en = mid - 1;
            }
        }

        return lastDay;
    }
};