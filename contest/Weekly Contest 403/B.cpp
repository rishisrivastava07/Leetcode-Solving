/*
Problem Statement - 3195 : Find the minimum area to cover all ones I.
ou are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.
Example 1:

Input: grid = [[0,1,0],[1,0,1]]

Output: 6

Explanation:
The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

Example 2:

Input: grid = [[1,0],[0,0]]

Output: 1

Explanation:



The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.
*/

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int firstRow = n, lastRow = -1;
        int firstCol = m, lastCol = -1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    if(i < firstRow) firstRow = i;
                    if(i > lastRow) lastRow = i;
                    if(j < firstCol) firstCol = j;
                    if(j > lastCol) lastCol = j;
                }
            }
        }
        int length = lastCol - firstCol + 1;
        int breadth = lastRow - firstRow + 1;
    
        return length * breadth;
    }
};