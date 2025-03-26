class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int n = grid.size();
            int m = grid[0].size();
    
            vector<int> vec;
            for(auto &row : grid){
                for(int &col : row){
                    vec.push_back(col);
                }
            }
    
            sort(begin(vec), end(vec));
    
            int len = vec.size();
            int target;
            if(len % 2 == 0) target = vec[len/2];
            else target = vec[(len + 1)/2 - 1];
    
            int ops = 0;
            for(int &i : vec){
                bool canExist = (abs(target - i) % x == 0);
                if(!canExist) return -1;
    
                ops += (abs(target - i)/x);
            } 
    
            return ops;
        }
    };