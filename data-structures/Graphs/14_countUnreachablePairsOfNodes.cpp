class Solution {
    int find(int i, vector<int>& parent){
        if(i == parent[i]) return i;
        
        return parent[i] = find(parent[i], parent);
    }
    
    void Union(int a, int b, vector<int>& parent, vector<int>& rank){
        int a_parent = find(a, parent);
        int b_parent = find(b, parent);
        
        if(a_parent == b_parent) return;
        if(rank[a_parent] > rank[b_parent]) parent[b_parent] = a_parent;
        else if(rank[a_parent] < rank[b_parent]) parent[a_parent] = b_parent;
        else {
            parent[b_parent] = a_parent;
            rank[a_parent]++;
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> rank(n, 1);
	    vector<int> parent(n);
        
	    for(int i = 0; i < n; i++) parent[i] = i;

        for(auto &u : edges){
            int xP = find(u[0], parent);
            int yP = find(u[1], parent);

            if(xP != yP){
                Union(u[0], u[1], parent, rank);
            }
        }

        unordered_map<int, int> mp;
        // component no. ---> size
        for(int i = 0; i < n; i++){
            int xP = find(i, parent);
            mp[xP]++;
        }

        long long result = 0;
        long long remainingNodes = n;

        for(auto& it: mp){
            result += it.second * (remainingNodes - it.second);
            remainingNodes -= it.second;
        }

        return result;
    }
};