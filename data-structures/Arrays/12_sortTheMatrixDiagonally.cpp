/*
    Problem Name : Sort the Matrix Diagonally 
    Company Tags : MICROSOFT
    LeetCode - 1329
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // Time Complexity - O(N^2) Space Complexity - O(N);
        int n = mat.size();
        int m = mat[0].size();

        // Store the key value pairs in diagonally downward fashion in mp
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[i-j].push_back(mat[i][j]);
            } 
        }

        // Sort the elements of map
        for(auto& it : mp){
            sort(begin(it.second), end(it.second));
        }

        // Store back the elements of mp to matrix from backwards
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return mat;
    }
};

int main(){
    // Driver Code
    return 0;
}