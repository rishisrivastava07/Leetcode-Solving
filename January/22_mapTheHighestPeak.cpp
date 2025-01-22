class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater){
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> height(n, vector<int>(m, -1));
        queue<P> que;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while(!que.empty()){
            int N = que.size();

            while(N--){
                P curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto& dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && height[i_][j_] == -1){
                        height[i_][j_] = height[i][j] + 1;
                        que.push({i_, j_});
                    }
                }
            }
        }

        return height;
    }
};