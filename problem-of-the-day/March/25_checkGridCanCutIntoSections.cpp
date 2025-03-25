class Solution {
    public:
        vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
            int n = intervals.size();
            sort(begin(intervals), end(intervals));
        
            vector<vector<int>> result;
            result.push_back(intervals[0]);
    
            for(int i = 1; i < n; i++){
                if(result.back()[1] <= intervals[i][0]){
                    result.push_back(intervals[i]);
                } else {
                    result.back()[0] = min(result.back()[0], intervals[i][0]);
                    result.back()[1] = max(result.back()[1], intervals[i][1]);
                }
            }
    
            return result;
        }
    
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            int sz = rectangles.size();
    
            vector<vector<int>> x_axis;
            vector<vector<int>> y_axis;
    
            for(vector<int> &rect: rectangles){
                x_axis.push_back({rect[0], rect[2]});
                y_axis.push_back({rect[1], rect[3]});
            } 
    
            vector<vector<int>> x_result = mergeIntervals(x_axis);
            if(x_result.size() >= 3) return true;
    
            vector<vector<int>> y_result = mergeIntervals(y_axis);
    
            return y_result.size() >= 3;
        }
    };