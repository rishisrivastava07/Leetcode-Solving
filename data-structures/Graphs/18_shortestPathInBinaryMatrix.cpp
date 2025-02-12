class Solution {
public:
    // Using BFS 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i == n-1 && j == m-1) return level+1;

                for(auto& dir : directions){
                    int i_ = i + dir.first;
                    int j_ = j + dir.second;

                    if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] == 0){
                        q.push({i_, j_});
                        grid[i_][j_] = 1;
                    }
                }
            }
            level++;
        }

        return -1;
    }
    
    // Using Dijkstra's Algorithm
    typedef pair<int, pair<int, int>> P;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        vector<vector<int>> result(n, vector<int> (m, INT_MAX));
     
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        grid[0][0] = 1;
        result[0][0] = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto& dir : directions){
                int x_ = x + dir.first;
                int y_ = y + dir.second;
                
                if(isSafe(x_, y_)  && grid[x_][y_] == 0){
                    if(dist + 1 < result[x_][y_]){
                        result[x_][y_] = dist + 1;
                        pq.push({dist+1, {x_, y_}});
                    }
                }
            }
        }

        return result[n-1][m-1] == INT_MAX ? -1 : result[n-1][m-1] + 1;
    }
};