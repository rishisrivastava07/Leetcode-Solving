class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Approach - 1
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            if(matrix[i][j] < target){
                i++;
            }
            else if(matrix[i][j] > target){
                j--;
            }
            else{
                return true;
            }
        } 

        // Approach - 2
        int st = 0, en = n*m - 1;

        while(st <= en){
            int mid = st + (en - st)/2;
            if(matrix[mid/m][mid%m] == target) return true;
            else if(matrix[mid/m][mid%m] < target) st = mid + 1;
            else en = mid - 1;
        }

        
        return false;
    }
};