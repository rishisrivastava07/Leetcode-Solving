class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int n = meetings.size();
            sort(begin(meetings), end(meetings));
    
            int freeDays = 0, end = 0;
    
            for(int i = 0; i < n; i++){
                if(meetings[i][0] > end){
                    freeDays += (meetings[i][0] - end - 1);
                }
    
                end = max(end, meetings[i][1]);
            }
    
            if(days > end){
                freeDays += (days - end);
            }
    
            return freeDays;
        }
    };