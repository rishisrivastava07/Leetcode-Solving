class Solution {
    public:
        struct edge {
            int u;
            int v;
            int maxVal;
            edge(int a, int b, int c) {
                u = a;
                v = b;
                maxVal = c;
            }
        };
    
        class DSU {
        private:
            vector<int> parent;
            vector<int> size;
        public:
            DSU(int n) {
                parent.resize(n);
                size.resize(n);
                for (int i = 0; i < n; i++)
                {
                    parent[i] = i;
                }
                for (int i = 0; i < n; i++)
                {
                    size[i] = 1;
                }
            }
            int find(int x) {
                if (parent[x] == x)
                    return x;
                parent[x] = find(parent[x]);
                return parent[x];
    
            }
            void unions(int x, int y) {
                int x_rep = find(x);
                int y_rep = find(y);
                if (x_rep == y_rep)
                    return;
                parent[y_rep] = x_rep;
                size[x_rep] += size[y_rep];
            }
            int getSize(int x) {
                return size[find(x)];
            }
        };
    
        bool isWithinGrid(int x, int y, int& r, int& c)
        {
            if (x < 0 || y < 0)
                return false;
            if (x >= r || y >= c)
                return false;
            return true;
        }
    
        void processEdges(vector<vector<int>>& grid, vector<edge>& allEdges)
        {
            int n = grid.size();
            int m = grid[0].size();
            int u, v;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    u = i * m + j;
                    if (isWithinGrid(i, j + 1, n, m)) {
                        v = i * m + j + 1;
                        edge temp(u, v, max(grid[i][j], grid[i][j + 1]));
                        allEdges.push_back(temp);
                    }
                    if (isWithinGrid(i + 1, j, n, m)) {
                        v = (i + 1) * m + j;
                        edge temp(u, v, max(grid[i][j], grid[i + 1][j]));
                        allEdges.push_back(temp);
                    }
                }
            }
        }
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    //Part 1:
            vector<edge> allEdges;
            int n = grid.size();
            int m = grid[0].size();
            processEdges(grid, allEdges);
            sort(begin(allEdges), end(allEdges),
                 [](edge a, edge b)
            {
                return a.maxVal < b.maxVal;
            });
    
    //Part 2:
            DSU ufobj(n * m);
    
    //Part 3:
            vector<pair<int, int>> q;
            for (int i = 0; i < queries.size(); ++i)
                q.push_back({queries[i], i});
    
            sort(begin(q), end(q));
    
    //Part 4:
            vector<int> ans(queries.size(), 0);
            int edPointer = 0;
    
            for (auto& currQ : q)
            {
                while (edPointer < allEdges.size() && allEdges[edPointer].maxVal < currQ.first)
                {
                    ufobj.unions(allEdges[edPointer].u, allEdges[edPointer].v);
                    edPointer++;
                }
                if (grid[0][0] < currQ.first)
                    ans[currQ.second] = ufobj.getSize(0);
            }
            return ans;
        }
    };