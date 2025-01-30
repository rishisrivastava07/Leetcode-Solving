class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> boundaryCells;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // left and right most column
        for(int row = 0; row < n; row++){
            for(int col : {0, m-1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // top and bottom most column
        for(int col = 0; col < m; col++){
            for(int row : {0, n-1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int waterTrap = 0;

        while(!boundaryCells.empty()){
            auto [height, cell] = boundaryCells.top();
            boundaryCells.pop();

            int i = cell.first;
            int j = cell.second;

            for(auto& dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];
  
                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !visited[i_][j_]){
                    waterTrap += max(height - heightMap[i_][j_], 0);
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }

        return waterTrap;
    }
};