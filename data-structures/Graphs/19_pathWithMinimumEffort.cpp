class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        vector<vector<int>> result (n, vector<int> (m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto& dir : directions){
                int x_ = x + dir.first;
                int y_ = y + dir.second;

                if(isSafe(x_, y_)){
                    int curr_diff = abs(heights[x_][y_] - heights[x][y]);
                    int max_diff = max(diff, curr_diff);
                    if(max_diff < result[x_][y_]){
                        pq.push({max_diff, {x_, y_}});
                        result[x_][y_] = max_diff;
                    }
                }
            }
        }

        return result[n-1][m-1];
    }
};