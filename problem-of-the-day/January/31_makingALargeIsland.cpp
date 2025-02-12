class Solution {
public:
    int n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int DFS(int i, int j, vector<vector<int>>& grid, int& id){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1){
            return 0;
        }

        grid[i][j] = id;
        int count = 1;

        for(auto& dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            count += DFS(i_, j_, grid, id);
        }

        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;
        unordered_map<int, int> mp;
        int id = 2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int size = DFS(i, j, grid, id);
                    maxArea = max(maxArea, size);
                    mp[id] = size;
                    id++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){ // checking for no land
                    unordered_set<int> uniqueIds;
                    for(auto& dir : directions){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];

                        if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] != 0){
                            uniqueIds.insert(grid[i_][j_]);
                        }
                    }

                    int overallSize = 1;
                    for(auto& id : uniqueIds){
                        overallSize += mp[id];
                    }

                    maxArea = max(maxArea, overallSize);
                }
            }
        }      

        return maxArea;
    }
};