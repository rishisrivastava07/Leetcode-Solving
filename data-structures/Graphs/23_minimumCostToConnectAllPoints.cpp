class Solution {
    typedef pair<int, int> P;
    typedef pair<int, pair<int, int>> p;
    
    int primsAlgo(vector<vector<P>>& adj, int V){
        // Step - 1 : Make an inMST & parent Vector. Also make a min heap
        vector<bool> inMST(V, false);
        vector<int> parentV(V, -1);
        
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, -1}});
        
        int sum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(inMST[node] == true) continue;
            
            inMST[node] = true;
            parentV[node] = parent;
            sum += wt;
            
            for(auto& vec : adj[node]){
                int adjNode = vec.first;
                int adjNode_wt = vec.second;
                
                if(!inMST[adjNode] && parentV[adjNode] == -1){
                    pq.push({adjNode_wt, {adjNode, node}});
                }
            }
        }
        
        return sum;
    }

    // Using Kruskals Algorithm
    int find(int i, vector<int>& parent){
        if(i == parent[i]) return i;
        
        return parent[i] = find(parent[i], parent);
    }
    
    void Union(int u, int v, vector<int>& parent, vector<int> &rank){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);
        
        if(parent_u == parent_v) return;
        else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        } else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        } else{
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }
    
    int kruskalsAlgorithm(vector<vector<int>>& vec, vector<int>& parent, vector<int>& rank){
        int sum = 0;
        
        for(auto& it : vec){
            int p1 = find(it[0], parent);
            int p2 = find(it[1], parent);
            
            if(p1 != p2){
                Union(p1, p2, parent, rank);
                sum += it[2];
            }
        }
        
        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        // making Adjecency List
        vector<vector<P>> adj(V);
        for(int i = 0; i < V; i++){
            for(int j = i+1; j < V; j++){
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        // Apply prim's algorithm
        return primsAlgo(adj, V);


        vector<vector<int>> vec;
        
        for(int u = 0; u < V; u++){
            for(auto& temp : adj[u]){
                int v = temp.first;
                int wt = temp.second;
                
                vec.push_back({u, v, wt});
            }
        }
        
        auto comparator = [&](vector<int>& vec1, vector<int>& vec2){
            return vec1[2] < vec2[2];
        };
        
        sort(begin(vec), end(vec), comparator);
     
        vector<int> parent(V);
        vector<int> rank(V, 1);
        
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        
        return kruskalsAlgorithm(vec, parent, rank);  
    }
};