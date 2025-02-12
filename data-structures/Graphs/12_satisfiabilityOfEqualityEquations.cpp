class Solution {
    int find(int x, vector<int> &parent){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x], parent);
    }

    void Union(int a, int b, vector<int> &parent, vector<int> &rank){
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
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 1);

        for(int i = 0; i < 26; i++) parent[i] = i; // 0th index --> 1 and so on...

        for(auto& s: equations){
            if(s[1] == '='){
                Union(s[0] - 'a', s[3] - 'a', parent, rank);
            }
        }

        for(auto& s: equations){
            if(s[1] == '!'){
                int x_parent = find(s[0] - 'a', parent);
                int y_parent = find(s[3] - 'a', parent);
                
                if(x_parent == y_parent) return false;
            }
        }

        return true;
    }
};