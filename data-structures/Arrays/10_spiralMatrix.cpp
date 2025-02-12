/*
    Problem Name : SPIRAL MATRIX
    Company Tags  :   Paytm, Zoho, Morgan Stanley, Accolite, Amazon, Microsoft, 
               Snapdeal, D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, 
               Nearbuy, Nagarro, BrowserStack
    Leetcode : 54
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int startCol = 0;
        int startRow = 0;
        int endCol = m - 1;
        int endRow = n - 1;

        vector<int> ans;
        int dir = 0;
        
        /*
            dir == 0 --> move from left to right
            dir == 1 --> move from top to bottom
            dir == 2 --> move from left to right
            dir == 3 --> move from bottom to top
        */

        while(startCol <= endCol && startRow <= endRow){
            if(dir == 0){
                for(int i = startCol; i <= endCol; i++){
                    ans.push_back(matrix[startRow][i]);
                }
                startRow++;
            }
            if(dir == 1){
                for(int i = startRow; i <= endRow; i++){
                    ans.push_back(matrix[i][endCol]);
                }
                endCol--;
            }
            if(dir == 2){
                for(int i = endCol; i >= startCol; i--){
                    ans.push_back(matrix[endRow][i]);
                }
                endRow--;
            }
            if(dir == 3){
                for(int i = endRow; i >= startRow; i--){
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }

            dir++;
            if(dir == 4) dir = 0;
        }
        return ans;
    }
};

int main(){
    // Driver Code  
    return 0;
}