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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(n-1 > edges) return -1;
        
        vector<int> rank(n, 1);
	    vector<int> parent(n);
	    
	    for(int i = 0; i < n; i++) parent[i] = i;

        int components = n;

        for(auto& comp : connections){
            int xP = find(comp[0], parent);
            int yP = find(comp[1], parent);

            if(xP != yP){
                Union(comp[0], comp[1], parent, rank);
                components--;
            }
        }

        return components - 1;
    }
};