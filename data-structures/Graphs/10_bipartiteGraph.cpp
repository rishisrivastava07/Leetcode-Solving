class Solution {
    bool DFS(int curr, vector<vector<int>>& g, vector<int> &color, int currColor){
        color[curr] = currColor;

        for(auto &v : g[curr]){
            if(color[v] == color[curr]) return false;
            if(color[v] == -1){
                int colorOfV = 1 - currColor;
                if(DFS(v, g, color, colorOfV) == false) return false;
            }
        }

        return true;
    }
    bool BFS(int curr, vector<vector<int>>& g, vector<int> &color, int currColor){
        queue<pair<int, int>> q;
        q.push({curr, currColor});
        color[curr] = currColor;

        while(!q.empty()){
            int frontNode = q.front().first;
            int currColored = q.front().second;
            q.pop();

            for(auto &v : g[frontNode]){
                if(color[v] == color[frontNode]) return false;

                if(color[v] == -1){
                    q.push({v, 1 - currColored});
                    color[v] = 1 - currColored;    
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& g) {
        int V = g.size();

        vector<int> color(V, -1);
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                // for DFS
                if(DFS(i, g, color, 1) == false) return false;
            
                // for BFS
                if(BFS(i, g, color, 1) == false) return false;
            }
        }

        return true;    
    }
};