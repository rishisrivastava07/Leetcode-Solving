/*
Problem Statement - 3169 : Count Days without Meeting
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

 

Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.

 

Constraints:

1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days   
*/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        sort(meetings.begin(), meetings.end());

        int total_engaged_days = 0;
        int current_start = meetings[0][0];
        int current_end = meetings[0][1];

        for (int i = 1; i < meetings.size(); ++i) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            if (start <= current_end + 1) {
                current_end = max(current_end, end);
            } else {
                total_engaged_days += current_end - current_start + 1;
                current_start = start;
                current_end = end;
            }
        }

        total_engaged_days += current_end - current_start + 1;

        int free_days = days - total_engaged_days;

        return free_days;
    }
};